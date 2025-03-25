#include <iostream>
#include <conio.h>
#include "human.h"
#include "world.h"
using namespace std;

struct sort_key
{
	inline bool operator() (Entity* entity1, Entity* entity2)
	{
		return (entity1->getInitiative() > entity2->getInitiative());
	}
};

Human::Human() {
	symbol = 2;
	abilityCooldown = 0;
	abilityReady = true;
	strength = 5;
	initiative = 4;
	x = 1;
	y = 1;
}

Human::Human(int xCoord, int yCoord) {
	symbol = 2;
	abilityCooldown = 0;
	abilityReady = true;
	strength = 5;
	initiative = 4;
	x = xCoord;
	y = yCoord;
}

int Human::getAbilityCooldown() {
	return abilityCooldown;
}


int Human::getAbilityReady() {
	return abilityReady;
}

void Human::setAbilityCooldown(int acd) {
	abilityCooldown = acd;
}

void Human::setAbilityReady(int ar) {
	abilityReady = ar;
}

int Human::ability() {
	if (abilityReady == 1) {
		abilityReady = 0;
		abilityCooldown = 10;
		return 2;
	}
	else if(abilityCooldown > 7) {
		abilityCooldown--;
		return 2;
	}
	else if (abilityCooldown < 8 && abilityCooldown > 5) {
		int chance = rand() % 2;
		if (chance == 1) {
			abilityCooldown--;
			return 2;
		}
		else {
			abilityCooldown--;
			return 1;
		}
	}
	else {
		abilityCooldown--;
		if (abilityCooldown == 0) {
			abilityReady = 1;
			return 0;
		}
	}
	return 1;
}

void Human::action(vector<Entity*>& entities, World* world, Logger &log, int width, int height) {
	int oldX = x, oldY = y;
	x = width;
	y = height;

	if (world->getEntity(x, y) != ' ') {
		for (int j = 0; j < entities.size(); j++) {
			if (x == entities[j]->getX() && y == entities[j]->getY() && this != entities[j]) {
				if (this != entities[j] && typeid(*this) == typeid(*entities[j])) {
					x = oldX;
					y = oldY;

					if (entities[j]->getX() < world->getWidth() && world->getEntity(entities[j]->getX() + 1, entities[j]->getY()) == ' ') {
						entities[j]->makeChild(entities, entities[j]->getX() + 1, entities[j]->getY());
						world->addEntity(entities[j]->getName(), entities[j]->getX() + 1, entities[j]->getY());
						log.addBirth(entities[j]);
						sort(entities.begin(), entities.end(), sort_key());
					}
					else if (entities[j]->getX() > 1 && world->getEntity(entities[j]->getX() - 1, entities[j]->getY()) == ' ') {
						entities[j]->makeChild(entities, entities[j]->getX() - 1, entities[j]->getY());
						world->addEntity(entities[j]->getName(), entities[j]->getX() - 1, entities[j]->getY());
						log.addBirth(entities[j]);
						sort(entities.begin(), entities.end(), sort_key());
					}
					else if (entities[j]->getY() > 1 && world->getEntity(entities[j]->getX(), entities[j]->getY() - 1) == ' ') {
						entities[j]->makeChild(entities, entities[j]->getX(), entities[j]->getY() - 1);
						world->addEntity(entities[j]->getName(), entities[j]->getX(), entities[j]->getY() - 1);
						log.addBirth(entities[j]);
						sort(entities.begin(), entities.end(), sort_key());
					}
					else if (entities[j]->getY() < world->getHeight() && world->getEntity(entities[j]->getX(), entities[j]->getY() + 1) == ' ') {
						entities[j]->makeChild(entities, entities[j]->getX(), entities[j]->getY() + 1);
						world->addEntity(entities[j]->getName(), entities[j]->getX(), entities[j]->getY() + 1);
						log.addBirth(entities[j]);
						sort(entities.begin(), entities.end(), sort_key());
					}
				}
				else if (entities[j]->collision(this) == 1) {
					if (this != entities[j]) {
						log.addKill(entities[j], this);
					}

				}
				else if (entities[j]->collision(this) == 0) {
					if (dynamic_cast<Animal*>(entities[j]) == nullptr) {
						if (this != entities[j]) {
							log.addFood(this, entities[j]);
						}
					}
					else {
						if (this != entities[j]) {
							log.addKill(this, entities[j]);
						}
					}
				}
				else if (entities[j]->collision(this) == 2) {
					x = oldX;
					y = oldY;
				}
				else  if (entities[j]->collision(this) == 3) {
					if (entities[j]->getX() < world->getWidth() && world->getEntity(entities[j]->getX() + 1, entities[j]->getY()) != ' ') {
						entities[j]->setCoords(entities[j]->getX() + 1, entities[j]->getY());
					}
					else if (entities[j]->getX() > 1 && world->getEntity(entities[j]->getX() - 1, entities[j]->getY()) != ' ') {
						entities[j]->setCoords(entities[j]->getX() - 1, entities[j]->getY());
					}
					else if (entities[j]->getY() > 1 && world->getEntity(entities[j]->getX(), entities[j]->getY() - 1) != ' ') {
						entities[j]->setCoords(entities[j]->getX(), entities[j]->getY() - 1);
					}
					else if (entities[j]->getY() < world->getHeight() && world->getEntity(entities[j]->getX(), entities[j]->getY() + 1) != ' ') {
						entities[j]->setCoords(entities[j]->getX(), entities[j]->getY() + 1);
					}
					else {
						entities[j]->setCoords(0, 0);
					}
				}
				break;
			}
		}
	}
	else {
		if (world->getEntity(x + 1, y) == 'B') {
			for (int j = 0; j < entities.size(); j++) {
				if (x + 1 == entities[j]->getX() && y == entities[j]->getY()) {
					entities[j]->collision(this);
					log.addKill(entities[j], this);
					break;
				}
			}
		}
		else if (world->getEntity(x - 1, y) == 'B') {
			for (int j = 0; j < entities.size(); j++) {
				if (x - 1 == entities[j]->getX() && y == entities[j]->getY()) {
					entities[j]->collision(this);
					log.addKill(entities[j], this);
					break;
				}
			}
		}
		else if (world->getEntity(x, y + 1) == 'B') {
			for (int j = 0; j < entities.size(); j++) {
				if (x == entities[j]->getX() && y + 1 == entities[j]->getY()) {
					entities[j]->collision(this);
					log.addKill(entities[j], this);
					break;
				}
			}
		}
		else if (world->getEntity(x, y - 1) == 'B') {
			for (int j = 0; j < entities.size(); j++) {
				if (x == entities[j]->getX() && y - 1 == entities[j]->getY()) {
					entities[j]->collision(this);
					log.addKill(entities[j], this);
					break;
				}
			}
		}
	}
}