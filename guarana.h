#pragma once
#include <iostream>
#include "plant.h"
using namespace std;

class Guarana : public Plant {
public:
	Guarana();

	Guarana(int xCoord, int yCoord);

	int collision(Entity* attacker) override;

	void makeChild(vector<Entity*>& entities, int x, int y) override;
};