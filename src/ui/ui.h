#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

class UI {
	public:
		UI();
		void render(sf::RenderWindow& window);

	private:
		sf::Font font;
		sf::Text test_text;
		float aspect;

		void initilize(sf::Font& font);
};