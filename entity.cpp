#include <iostream>
#include <conio.h>
#include "entity.h"
using namespace std;


int Entity::getStrength() {
	return strength;
}

void Entity::setStrength(int str) {
	strength = str;
}

void Entity::boost() {
	strength += 3;
}

int Entity::getInitiative() {
	return initiative;
}

int Entity::getX() {
	return x;
}

int Entity::getY() {
	return y;
}

void Entity::setCoords(int xCoord, int yCoord) {
	x = xCoord;
	y = yCoord;
}

void Entity::drawEntity() {
	printf("\033[%d;%dH", y, x * 2 - 1);
	cout << symbol << ' ';
}

void Entity::moveEntity(int newX, int newY) {
	printf("\033[%d;%dH", y, x * 2 - 1);
	cout << "  ";
	setCoords(newX, newY);
	drawEntity();
}

char Entity::getName() {
	return symbol;
}
