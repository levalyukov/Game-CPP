#pragma once

#include "ui-element.hpp"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Label : public UIElement {
	public:
		Label(
			std::string message,
			sf::Font& font,
			unsigned int size,
			sf::Color color,
			sf::Vector2f position
		);

		void draw(sf::RenderWindow& window) const;

	private:
		std::string message;
		const sf::Font& font;
		unsigned int size;
		sf::Text text;
		sf::Color color;
		sf::Vector2f position;
};