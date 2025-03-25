#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Sheep : public Animal {
public:
	Sheep();

	Sheep(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};