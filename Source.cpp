#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <typeinfo>
#include "world.h"
#include "human.h"
#include "wolf.h"
#include "sheep.h"
#include "turtle.h"
#include "fox.h"
#include "antelope.h"
#include "grass.h"
#include "guarana.h"
#include "dandelion.h"
#include "nightshade.h"
#include "borscht.h"
#include "logger.h"
using namespace std;

struct sort_key
{
	inline bool operator() (Entity* entity1, Entity* entity2)
	{
		return (entity1->getInitiative() > entity2->getInitiative());
	}
};

void loadVector(vector<Entity*>& entities, World* map, char name, int x, int y, int strength) {
	if (name == 'A') {
		entities.push_back(new Antelope(x, y));
	} 
	else if(name == 'B') {
		entities.push_back(new Borscht(x, y));
	}
	else if(name == 'M') {
		entities.push_back(new Dandelion(x, y));
	}
	else if(name == 'L') {
		entities.push_back(new Fox(x, y));
	}
	else if(name == 'T') {
		entities.push_back(new Grass(x, y));
	}
	else if(name == 'G') {
		entities.push_back(new Guarana(x, y));
	}
	else if(name == 2) {
		entities.push_back(new Human(x, y));
	}
	else if (name == 'J') {
		entities.push_back(new Nightshade(x, y));
	}
	else if(name == 'O') {
		entities.push_back(new Sheep(x, y));
	}
	else if (name == 'Z') {
		entities.push_back(new Turtle(x, y));
	}
	else if (name == 'w') {
		entities.push_back(new Wolf(x, y));
	}
	entities[entities.size()-1]->setStrength(strength);
	map->addEntity(name, x, y);
}

int main() {
	int width = 0, height = 0, i = 0, humanx, humany, oldX, oldY, tempX, tempY, entityCount = 0, direction, movement = 1, triggerPower = 0, checked = 0, strength, ar, acd;
	char input, name;
	Logger log;
	char filename[256];
	FILE* save;
	vector <Entity*> entities;
	printf("\033[%d;%dH", 1, 1);
	cout << "Nowa gra - n" << endl;
	cout << "Wczytaj gre - l" << endl;
	cin >> input;
	while (input != 'n' && input != 'l') {
		cin >> input;
	}

	if (input == 'n') {
		system("CLS");
		printf("\033[%d;%dH", 1, 1);
		cout << "Szerokosc: ";
		cin >> width;
		cout << "Wysokosc: ";
		cin >> height;

	}
	else {
		system("CLS");
		printf("\033[%d;%dH", 1, 1);
		cout << "Wpisz nazwe zapisu: ";
		cin >> filename;
		for (int i = 0; i < 250; i++) {
			if (filename[i] == 0) {
				filename[i] = '.';
				filename[i + 1] = 't';
				filename[i + 2] = 'x';
				filename[i + 3] = 't';
				filename[i + 4] = 0;
				break;
			}
		}
		save = fopen(filename, "r");
		fscanf(save, "%d\n%d", &width, &height);
		fclose(save);
	}

	World world(width, height);

	if(input == 'n'){
		humanx = width / 2;
		humany = height / 2;
		entities.push_back(new Human(humanx, humany));
		world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
		entityCount++;
		for (int i = 0; i < (width * height) / 100; i++) {
			tempX = rand() % width;
			tempY = rand() % height;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Sheep(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			if (i % 2 == 0) {
				while (world.getEntity(tempX, tempY) != ' ') {
					tempX = rand() % width;
					tempY = rand() % height;
				}
				entities.push_back(new Wolf(tempX, tempY));
				world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
				entityCount++;
			}
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Turtle(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Fox(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Antelope(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Grass(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Guarana(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Borscht(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Nightshade(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			while (world.getEntity(tempX, tempY) != ' ') {
				tempX = rand() % width;
				tempY = rand() % height;
			}
			entities.push_back(new Dandelion(tempX, tempY));
			world.addEntity(entities[entityCount]->getName(), entities[entityCount]->getX(), entities[entityCount]->getY());
			entityCount++;
			sort(entities.begin(), entities.end(), sort_key());
		}
	} else {
		save = fopen(filename, "r");
		fscanf(save, "%d\n%d", &width, &height);
		fscanf(save, "\n%d\n", &entityCount);
		for (int i = 0; i < entityCount; i++) {
			fscanf(save, "%c %d %d %d\n", &input, &tempX, &tempY, &strength);
			loadVector(entities, &world, input, tempX, tempY, strength);
		}
		fscanf(save, "%d %d\n", &ar, &acd);
		fclose(save);
		for (int i = 0; i < entityCount; i++) {
			if (dynamic_cast<Human*>(entities[i]) != nullptr) {
				humanx = entities[i]->getX();
				humany = entities[i]->getY();
				entities[i]->setAbilityReady(ar);
				entities[i]->setAbilityCooldown(acd);
				break;
			}
		}
	}

	cout << endl;
	system("CLS");
	printf("\033[%d;%dH", 1, 1);

	world.drawWorld();
	world.updateMap();
	input = _getch();
	
	while (input != 'q') {
		input = _getch();
		switch (input) {
		case 'K':
			if (humanx > 1) {
				if (movement > 1 && humanx < 3) {
					movement = 1;
				}
				humanx -= movement;
			}
			break;
		case 'M':
			if (humanx < width) {
				if (movement > 1 && humanx > width - 2) {
					movement = 1;
				}
				humanx += movement;
			}
			break;
		case 'H':
			if (humany > 1) {
				if (movement > 1 && humany < 3) {
					movement = 1;
				}
				humany -= movement;
			}
			break;
		case 'P':
			if (humany < height) {
				if (movement > 1 && humany > height - 2) {
					movement = 1;
				}
				humany += movement;
			}
			break;
		case '<':
			if (triggerPower == 0) {
				triggerPower = 1;
			}
			break;
		case '=':
			system("CLS");
			printf("\033[%d;%dH", 1, 1);
			cout << "wpisz nazwe zapisu : ";
			cin >> filename;
			for (int i = 0; i < 250; i++) {
				if (filename[i] == 0) {
					filename[i] = '.';
					filename[i+1] = 't';
					filename[i+2] = 'x';
					filename[i+3] = 't';
					filename[i + 4] = 0;
					break;
				}
			}
			save = fopen(filename, "w");
			fprintf(save, "%d\n%d", width, height);
			fprintf(save, "\n%d\n", int(entities.size()));
			for (int i = 0; i < entities.size(); i++) {
				name = entities[i]->getName();
				tempX = entities[i]->getX();
				tempY = entities[i]->getY();
				fprintf(save, "%c %d %d %d\n", name, tempX, tempY, entities[i]->getStrength());
			}
			for (int i = 0; i < entities.size(); i++) {
				if (dynamic_cast<Human*>(entities[i]) != nullptr) {
					fprintf(save, "%d %d\n", entities[i]->getAbilityReady(), entities[i]->getAbilityCooldown());
					break;
				}
			}
			fclose(save);
			break;
		}

		for (int i = 0; i < entities.size(); i++) {
			if (dynamic_cast<Human*>(entities[i]) != nullptr && triggerPower == 1) {
				movement = entities[i]->ability();
				if (movement == 0) {
					movement = 1;
					triggerPower = 0;
				}
			}
			if (entities[i] != nullptr && entities[i]->getX() != 0 && entities[i]->getY() != 0) {
				oldX = entities[i]->getX();
				oldY = entities[i]->getY();

				if (dynamic_cast<Human*>(entities[i]) != nullptr) {
					entities[i]->action(entities, &world, log, humanx, humany);
				}
				else {
					entities[i]->action(entities, &world, log, width, height);
				}

				world.updateEntity(entities[i]->getName(), entities[i]->getX(), entities[i]->getY(), oldX, oldY);
			}
		}
		
		for (int i = 0; i < entities.size(); i++) {
			if (entities[i]->getX() == 0, entities[i]->getY() == 0) {
				entities.erase(entities.begin() + i);
			}
		}

		world.updateMap();
		system("CLS");
		printf("\033[%d;%dH", 1, 1);
		world.drawWorld();
		world.updateMap();

		printf("\033[%d;%dH", height+3, 1);
		log.write();
		log.clear();
		input = _getch();
	}
}