#pragma once
#include <iostream>
#include <vector>
#include "entity.h"
#include "world.h"
#include "plant.h"
using namespace std;

struct sort_key;

class Animal : public Entity {
public:

	void action(vector<Entity*>& entities, World *map, Logger &log, int width, int height) override;

	int ability() override;

	int collision(Entity* attacker) override;

	void makeChild(vector<Entity*> &entities, int x, int y) override;

	int getAbilityCooldown() override;

	int getAbilityReady() override;

	void setAbilityCooldown(int acd) override;

	void setAbilityReady(int ar) override;
};
