#pragma once
#include <iostream>
#include <conio.h>
#include "entity.h"
using namespace std;

class World {
private:
	int width;
	int height;
	char* map;
public:
	World();

	World(int w, int h);

	void drawWorld();

	void addEntity(char name, int x, int y);

	void removeEntity(int x, int y);

	void doTurn();

	int getWidth();

	int getHeight();

	void setWidth(int w);

	void setHeight(int h);

	void updateMap();

	void updateEntity(char name, int x, int y, int oldX, int oldY);

	char getEntity(int x, int y);
};