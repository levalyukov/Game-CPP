#pragma once

#include <SFML/Graphics.hpp>

class Entity {
	public:
		virtual void render(sf::RenderWindow& window, float deltaTime, sf::View& gameCamera) = 0;
};