#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../../economy/economy.hpp"
#include "../../entities/player.hpp"

class UI {
	public:
		UI();
		void render(sf::RenderWindow& window, sf::View& uiView);

	private:
		sf::Font font;
		sf::View ui;
		sf::Vector2f viewSize;

		// UI elements
		sf::Text coins;

		Player player;
		Economy economy;

		enum Alignment {
			TopLeft
		};

		void initilize(sf::Font& font);
		void setElementPosition(Alignment alignment, sf::Text& ui, float offsetX, float offsetY);
		void createHUD();
};