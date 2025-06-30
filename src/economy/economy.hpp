#pragma once

#include <iostream>
#include <cstdlib>

class Economy {
	public:
		unsigned int money = 0;

		void setMoney(int value);
		void addMoney(int value);
		void removeMoney(int value);
};