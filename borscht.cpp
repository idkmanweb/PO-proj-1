#include <iostream>
#include <conio.h>
#include "borscht.h"
using namespace std;


Borscht::Borscht() {
	symbol = 'B';
	strength = 10;
	initiative = 0;
	x = 1;
	y = 1;
}

Borscht::Borscht(int xCoord, int yCoord) {
	symbol = 'B';
	strength = 10;
	initiative = 0;
	x = xCoord;
	y = yCoord;
}

void Borscht::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Borscht(x, y));
}

int Borscht::collision(Entity* attacker) {
	attacker->setCoords(0, 0);
	return 1;
}