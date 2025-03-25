#pragma once
#include <iostream>
#include "plant.h"
using namespace std;

class Nightshade : public Plant {
public:
	Nightshade();

	Nightshade(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;

	int collision(Entity* attacker) override;
};