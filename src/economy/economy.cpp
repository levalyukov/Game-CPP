#include "economy.hpp";

void Economy::setMoney(int value) {
	if (value > 0) {
		money = value;
	}
}

void Economy::addMoney(int value) {
	if (value > 0) {
		money += value;
	}
}

void Economy::removeMoney(int value) {
	if (value > 0) {
		money -= value;
	}
}