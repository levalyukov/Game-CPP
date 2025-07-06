#pragma once

#include "elements/label.hpp"
#include "elements/button.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>

class GUI {
	public:
		std::unique_ptr<Label> createLabel(
			std::string message, 
			sf::Font* font, 
			unsigned __int8 size,
			sf::Color font_color,
			sf::Vector2f coords_pos,
			UIElement::ElementPosition position
		);

		std::unique_ptr<Button> createButton(
			sf::Texture* texture,
			sf::Vector2f coords_pos
		);
};