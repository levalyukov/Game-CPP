#include "economy.hpp";

void Economy::setMoney(int value) {
	if (value < 0) {
		money = 0;
		return;
	}

	money = value;
}

void Economy::addMoney(int value) {
	if (value < 0) {
		std::cerr << "Error: Value not can't be less zero." << std::endl;
		return;
	}
	
	money += value;
}

void Economy::removeMoney(int value) {
	if (value < 0) {
		std::cerr << "Error: Value not can't be less zero." << std::endl;
		return;
	}

	money -= value;
}