#include <iostream>
#include <conio.h>
#include "wolf.h"
using namespace std;


Wolf::Wolf() {
	symbol = 'W';
	strength = 9;
	initiative = 5;
	x = 1;
	y = 1;
}

Wolf::Wolf(int xCoord, int yCoord) {
	symbol = 'W';
	strength = 9;
	initiative = 5;
	x = xCoord;
	y = yCoord;
}

void Wolf::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Wolf(x, y));
}