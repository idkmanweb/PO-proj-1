#pragma once
#include <iostream>
#include "plant.h"
using namespace std;

class Borscht : public Plant {
public:
	Borscht();

	Borscht(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;

	int collision(Entity* attacker) override;
};