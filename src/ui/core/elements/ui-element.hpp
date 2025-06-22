#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class UIElement {
	public:
		virtual void draw(sf::RenderWindow& window) const = 0;
};