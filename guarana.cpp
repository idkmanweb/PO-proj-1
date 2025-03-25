#include <iostream>
#include <conio.h>
#include "guarana.h"
using namespace std;


Guarana::Guarana() {
	symbol = 'G';
	strength = 0;
	initiative = 0;
	x = 1;
	y = 1;
}

Guarana::Guarana(int xCoord, int yCoord) {
	symbol = 'G';
	strength = 0;
	initiative = 0;
	x = xCoord;
	y = yCoord;
}

int Guarana::collision(Entity* attacker) {
	if (attacker != this) {
		attacker->boost();
		x = 0;
		y = 0;
		return 0;
	}
}

void Guarana::makeChild(vector<Entity*>& entities, int x, int y) {
	entities.push_back(new Guarana(x, y));
}