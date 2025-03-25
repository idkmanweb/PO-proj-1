#include <iostream>
#include <conio.h>
#include "animal.h"
#include "fox.h"
using namespace std;

struct sort_key
{
	inline bool operator() (Entity* entity1, Entity* entity2)
	{
		return (entity1->getInitiative() > entity2->getInitiative());
	}
};

void Animal::action(vector<Entity*>& entities, World* world, Logger &log, int width, int height) {
	int direction = rand() % 4;
	if (direction == 0 && x < width) {
		x++;
	} 
	else if (direction == 1 && x > 1) {
		x--;
	}
	else if(direction == 2 && y > 1) {
		y--;
	}
	else if(direction == 3 && y < height) {
		y++;
	}

	if (world->getEntity(x, y) != ' ') {
		for (int j = 0; j < entities.size(); j++) {
			if (x == entities[j]->getX() && y == entities[j]->getY()) {
				if (this != entities[j] && typeid(*this) == typeid(*entities[j])) {
					if (direction == 0) {
						x--;
					}
					else if (direction == 1) {
						x++;
					}
					else if (direction == 2) {
						y++;
					}
					else if (direction == 3) {
						y--;
					}

					if (entities[j]->getX() < width && world->getEntity(entities[j]->getX() + 1, entities[j]->getY()) == ' ') {
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
					else if (entities[j]->getY() < height && world->getEntity(entities[j]->getX(), entities[j]->getY() + 1) == ' ') {
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
					if (direction == 0) {
						x--;
					}
					else if (direction == 1) {
						x++;
					}
					else if (direction == 2) {
						y++;
					}
					else if (direction == 3) {
						y--;
					}
				}
				else  if (entities[j]->collision(this) == 3) {
					if (entities[j]->getX() < width && world->getEntity(entities[j]->getX() + 1, entities[j]->getY()) != ' ') {
						entities[j]->setCoords(entities[j]->getX() + 1, entities[j]->getY());
					}
					else if (entities[j]->getX() > 1 && world->getEntity(entities[j]->getX() - 1, entities[j]->getY()) != ' ') {
						entities[j]->setCoords(entities[j]->getX() - 1, entities[j]->getY());
					}
					else if (entities[j]->getY() > 1 && world->getEntity(entities[j]->getX(), entities[j]->getY() - 1) != ' ') {
						entities[j]->setCoords(entities[j]->getX(), entities[j]->getY() - 1);
					}
					else if (entities[j]->getY() < height && world->getEntity(entities[j]->getX(), entities[j]->getY() + 1) != ' ') {
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

int Animal::collision(Entity* attacker) {
	if (attacker != this) {
		if (strength > attacker->getStrength()) {
			if (dynamic_cast<Fox*>(attacker) == nullptr) {
				attacker->setCoords(0, 0);
				return 1;
			}
			else {
				return 2;
			}
		}
		else {
			x = 0;
			y = 0;
			return 0;
		}
	}
}

void Animal::makeChild(vector<Entity*>& entities, int x, int y) {}

int Animal::ability() {
	return 0;
}

int Animal::getAbilityCooldown() {
	return 0;
}


int Animal::getAbilityReady() {
	return 0;
}

void Animal::setAbilityCooldown(int acd) {}

void Animal::setAbilityReady(int ar) {}