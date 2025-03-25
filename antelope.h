#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Antelope : public Animal {
public:
	Antelope();

	Antelope(int xCoord, int yCoord);

	void action(vector<Entity*>& entities, World* map, Logger &log, int width, int height) override;

	int collision(Entity* attacker) override;

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};
