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
			ElementPosition position,
			bool visible
		);

		void setText(std::string new_string);

		bool getVisible() { return isVisible; };

		void draw(sf::RenderWindow& window) const;
		void setVisible(bool visible) { isVisible = visible; };

	private:
		std::string message;
		const sf::Font& font;
		unsigned __int8 size;
		sf::Text text;
		sf::Color color;
		sf::Vector2f coords_pos;
		ElementPosition position;
		bool isVisible;
};