#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../economy/economy.hpp"
#include "../entities/player.hpp"

class UserInterfaceManager {
	public:
		enum ElementType {
			Text,
			Menu,
			Button
		};

		void createElement(
			std::string name,
			ElementType type,
			int indexZ
		);

	private:
		sf::Font font;
};