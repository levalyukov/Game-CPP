#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class UIElement {
	public:
		enum ElementPosition {
			TopLeft, TopCenter, TopRight,
			MiddleLeft, MiddleCenter, MiddleRight,
			BottomLeft, BottomCenter, BottomRight
		};

		virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
		virtual void draw(sf::RenderWindow& window) const = 0;
};