#pragma once
#include <iostream>
#include "world.h"
#include "entity.h"
using namespace std;

class Entity;

class Logger {
private:

	string log;

public:

	Logger();

	void addKill(Entity* attacker, Entity* pray);

	void addFood(Entity* animal, Entity* food);

	void addBirth(Entity* animal);

	void addPlant(Entity* plant);

	void write();

	void clear();

};