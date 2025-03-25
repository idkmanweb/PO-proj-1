#include <iostream>
#include <conio.h>
#include "grass.h"
using namespace std;


Grass::Grass() {
	symbol = 'T';
	strength = 0;
	initiative = 0;
	x = 1;
	y = 1;
}

Grass::Grass(int xCoord, int yCoord) {
	symbol = 'T';
	strength = 0;
	initiative = 0;
	x = xCoord;
	y = yCoord;
}

void Grass::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Grass(x, y));
}