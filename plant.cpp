#include <iostream>
#include <conio.h>
#include <vector>
#include "plant.h"
using namespace std;


void Plant::action(vector<Entity*>& entities, World *map, Logger &log, int width, int height) {
	int chance = rand() % 40;
	if (chance == 1) {
		if (x < width && map->getEntity(x + 1, y) == ' ') {
			makeChild(entities, x + 1, y);
			map->addEntity(symbol, x + 1, y);
			log.addPlant(this);
		}
		else if (x > 1 && map->getEntity(x - 1, y) == ' ') {
			makeChild(entities, x - 1, y);
			map->addEntity(symbol, x - 1, y);
			log.addPlant(this);
		}
		else if (y > 1 && map->getEntity(x, y - 1) == ' ') {
			makeChild(entities, x, y - 1);
			map->addEntity(symbol, x, y - 1);
			log.addPlant(this);
		}
		else if (y < height && map->getEntity(x, y + 1) == ' ') {
			makeChild(entities, x, y + 1);
			map->addEntity(symbol, x, y + 1);
			log.addPlant(this);
		}
	}
}

int Plant::collision(Entity* attacker) {
	if (attacker != this) {
		if (strength > attacker->getStrength()) {
			attacker->setCoords(0, 0);
			return 1;
		}
		else {
			x = 0;
			y = 0;
			return 0;
		}
	}
}

void Plant::makeChild(vector<Entity*>& entities, int x, int y) {}

int Plant::ability() {
	return 0;
}

int Plant::getAbilityCooldown() {
	return 0;
}


int Plant::getAbilityReady() {
	return 0;
}

void Plant::setAbilityCooldown(int acd) {}

void Plant::setAbilityReady(int ar) {}