#include <iostream>
#include "world.h"
using namespace std;


World::World() {
	width = 0;
	height = 0;
	*(map) = '\0';
}

World::World(int w, int h) {
	width = w;
	height = h;
	map = new char[width * height];
	for (int i = 0; i < height * width; i++) {
		map[i] = ' ';
	}
}

void World::drawWorld() {
	printf("\033[%d;%dH", 0, 0);
	for (int i = 0; i < (width + 2); i++) {
		cout << "##";
	}
	cout << endl;
	for (int i = 0; i < (width + 2) * (height); i++) {
		if (i % (width + 2) == 0) {
			cout << " #";
		}
		else if (i % (width + 2) == width + 1) {
			cout << "# ";
			cout << endl;
		}
		else {
			cout << "  ";
		}
	}

	for (int i = 0; i < (width + 2); i++) {
		cout << "##";
	}
}

void World::updateMap() {
	printf("\033[%d;%dH", 2, 3);

	for (int i = 0; i < width * height; i++) {
		cout << map[i] << " ";
		if (i % width == width - 1) {
			cout << endl << " #";
		}
	}
}

void World::addEntity(char name, int x, int y) {
	map[(y - 1) * width + (x - 1)] = name;
}

void World::updateEntity(char name, int x, int y, int oldX, int oldY) {
	if (map[(oldY - 1) * width + (oldX - 1)] == name) {
		map[(oldY - 1) * width + (oldX - 1)] = ' ';
	}
	map[(y - 1) * width + (x - 1)] = name;
}

void World::removeEntity(int x, int y) {
	map[(y - 1) * width + (x - 1)] = ' ';
}

void World::doTurn() {

}

int World::getWidth() {
	return width;
}

int World::getHeight() {
	return height;
}

void World::setWidth(int w) {
	width = w;
}

void World::setHeight(int h) {
	height = h;
}

char World::getEntity(int x, int y) {
	return map[(y - 1) * width + (x - 1)];
}