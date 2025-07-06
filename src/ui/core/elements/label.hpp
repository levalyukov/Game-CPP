#pragma once

#include "ui-element.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Label : public UIElement {
	public:
		Label(
			std::string message,
			sf::Font* font,
			unsigned __int8 size,
			sf::Color color,
			sf::Vector2f coords_position,
			ElementPosition position
		);

		void setText(std::string new_string);

		void handleEvent(sf::Event& event, sf::RenderWindow& window) {};
		void draw(sf::RenderWindow& window) const;

	private:
		std::string message;
		const sf::Font& font;
		unsigned __int8 size;
		sf::Text text;
		sf::Color color;
		sf::Vector2f coords_pos;
		ElementPosition position;
};