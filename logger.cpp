#include <iostream>
#include <conio.h>
#include <string>
#include "logger.h"
#include "entity.h"
using namespace std;

Logger::Logger() {
	log = "";
}

void Logger::addKill(Entity* attacker, Entity* prey) {
	log += "\n";
	log += attacker->getName();
	log += " zabil ";
	log += prey->getName();
	log += " w (";
	log += to_string(attacker->getX());
	log += ",";
	log += to_string(attacker->getY());
	log += ")";
}

void Logger::addFood(Entity* animal, Entity* food) {
	log += "\n";
	log += animal->getName();
	log += " zjadl ";
	log += food->getName();
	log += " w (";
	log += to_string(animal->getX());
	log += ",";
	log += to_string(animal->getY());
	log += ")";
}

void Logger::addBirth(Entity* animal) {
	log += "\n";
	log += animal->getName();
	log += " urodzil sie w (";
	log += to_string(animal->getX());
	log += ",";
	log += to_string(animal->getY());
	log += ")";
}

void Logger::addPlant(Entity* plant) {
	log += "\n";
	log += plant->getName();
	log += " rozpylil sie w (";
	log += to_string(plant->getX());
	log += ",";
	log += to_string(plant->getY());
	log += ")";
}

void Logger::write() {
	cout << log;
}

void Logger::clear() {
	log = "";
}