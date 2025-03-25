#pragma once
#include <iostream>
#include "plant.h"
#include "world.h"
using namespace std;

class Dandelion : public Plant {
public:
	Dandelion();

	Dandelion(int xCoord, int yCoord);

	void action(vector<Entity*>& entities, World *map, Logger &log, int width, int height) override;

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};