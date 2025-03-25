#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Wolf : public Animal {
public:
	Wolf();

	Wolf(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};