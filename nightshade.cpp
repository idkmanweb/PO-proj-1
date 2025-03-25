#include <iostream>
#include <conio.h>
#include "nightshade.h"
using namespace std;


Nightshade::Nightshade() {
	symbol = 'J';
	strength = 99;
	initiative = 0;
	x = 1;
	y = 1;
}

Nightshade::Nightshade(int xCoord, int yCoord) {
	symbol = 'J';
	strength = 99;
	initiative = 0;
	x = xCoord;
	y = yCoord;
}

void Nightshade::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Nightshade(x, y));
}

int Nightshade::collision(Entity* attacker) {
	attacker->setCoords(0, 0);
	return 1;
}