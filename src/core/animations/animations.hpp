#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
class Animations {
	public:
		void setAnimation(
			sf::Sprite& sprite,
			sf::Texture& texture,
			sf::Vector2i& animStart,
			int frameCount,
			int frameX,
			int frameY,
			float& animationTimer,
			float frameDuration,
			float deltaTime
		);
};

