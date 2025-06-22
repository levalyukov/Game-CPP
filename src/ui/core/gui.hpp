#pragma once

#include "elements/label.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>

class GUI {
	public:
		// Label
		std::unique_ptr<Label> createLabel(
			std::string message, 
			sf::Font* font, 
			unsigned __int8 size,
			sf::Color font_color,
			sf::Vector2f coords_pos,
			UIElement::ElementPosition position,
			bool visible
		);
};