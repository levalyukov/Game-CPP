#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
class Animations {
public:
	void UpdateAnimation(
		sf::Sprite& sprite,
		sf::Texture& textureSet,
		sf::Vector2i& startPosition,
		int frameCount,
		int frameX,
		int frameY,
		float& animationTimer,
		float frameDuration,
		float deltaTime
	);
};

