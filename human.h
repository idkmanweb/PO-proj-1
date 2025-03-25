#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Human : public Animal {
private:
	bool abilityReady;
	int abilityCooldown;
	
public:

	Human();

	Human(int xCoord, int yCoord);

	int ability() override;

	void action(vector<Entity*>& entities, World* map, Logger &log, int width, int height) override;

	int getAbilityCooldown() override;

	int getAbilityReady() override;

	void setAbilityCooldown(int acd) override;

	void setAbilityReady(int ar) override;
};