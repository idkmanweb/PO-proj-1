#include <iostream>
#include <conio.h>
#include "dandelion.h"
using namespace std;


Dandelion::Dandelion() {
	symbol = 'M';
	strength = 0;
	initiative = 0;
	x = 1;
	y = 1;
}

Dandelion::Dandelion(int xCoord, int yCoord) {
	symbol = 'M';
	strength = 0;
	initiative = 0;
	x = xCoord;
	y = yCoord;
}

void Dandelion::action(vector<Entity*>& entities, World *map, Logger& log, int width, int height) {
	for (int i = 0; i < 3; i++) {
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
}

void Dandelion::makeChild(vector<Entity*> &entities, int x, int y) {
	entities.push_back(new Dandelion(x, y));
}