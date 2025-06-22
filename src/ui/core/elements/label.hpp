#pragma once

#include "ui-element.hpp"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Label : public UIElement {
	public:
		Label(
			std::string name_element,
			std::string message,
			sf::Font* font,
			unsigned __int8 size,
			sf::Color color,
			sf::Vector2f position
		);

		void setText(std::string& new_string);

		void draw(sf::RenderWindow& window) const;

	private:
		std::string name;
		std::string message;
		const sf::Font& font;
		unsigned __int8 size;
		sf::Text text;
		sf::Color color;
		sf::Vector2f position;
};