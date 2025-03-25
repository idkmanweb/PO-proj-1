#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "world.h"
#include "logger.h"
using namespace std;

class Logger;
class World;

class Entity {
protected:

	int strength, initiative, x, y;
	char symbol;

public:

	virtual void action(vector<Entity*>& entities, World *map, Logger &log, int width, int height) = 0;

	virtual int collision(Entity* attacker) = 0;

	virtual void makeChild(vector<Entity*> &entities, int x, int y) = 0;

	virtual int ability() = 0;

	virtual int getAbilityCooldown() = 0;

	virtual int getAbilityReady() = 0;

	virtual void setAbilityCooldown(int acd) = 0;

	virtual void setAbilityReady(int ar) = 0;

	void drawEntity();

	int getStrength();

	void setStrength(int str);

	void boost();

	int getInitiative();

	int getX();

	int getY();

	char getName();

	void setCoords(int xCoord, int yCoord);

	void moveEntity(int newX, int newY);
};