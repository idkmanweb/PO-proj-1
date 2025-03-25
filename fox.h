#pragma once
#include <iostream>
#include <vector>
#include "animal.h"
using namespace std;

class Fox : public Animal {
public:
	Fox();

	Fox(int xCoord, int yCoord);

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};