#include <iostream>
#include <conio.h>
#include "sheep.h"
using namespace std;


Sheep::Sheep() {
	symbol = 'O';
	strength = 4;
	initiative = 4;
	x = 1;
	y = 1;
}

Sheep::Sheep(int xCoord, int yCoord) {
	symbol = 'O';
	strength = 4;
	initiative = 4;
	x = xCoord;
	y = yCoord;
}

void Sheep::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Sheep(x, y));
}