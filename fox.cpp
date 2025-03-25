#include <iostream>
#include <conio.h>
#include "fox.h"
using namespace std;


Fox::Fox() {
	symbol = 'L';
	strength = 3;
	initiative = 7;
	x = 1;
	y = 1;
}

Fox::Fox(int xCoord, int yCoord) {
	symbol = 'L';
	strength = 3;
	initiative = 7;
	x = xCoord;
	y = yCoord;
}

void Fox::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Fox(x, y));
}