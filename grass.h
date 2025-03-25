#pragma once
#include <iostream>
#include "plant.h"
using namespace std;

class Grass : public Plant {
public:
	Grass();

	Grass(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};