#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "../systems/animations/animations.h"

const float WALK_SPEED = 4.0f;
const int RUN_SPEED = 6.0f;

class Player {
	public:
		Player();
		void render(sf::RenderWindow& window, float& deltaTime);
		void movement(float& deltaTime);

	private:
		Animations animations;

		sf::Sprite sprite;
		sf::Texture texture_walk_vertical;
		sf::Texture texture_walk_horizontal;
		sf::Texture texture_idle;
		sf::View view;

		std::string direction;
		sf::Vector2i animWalk_UP = { 0,16 };
		sf::Vector2i animWalk_DOWN = { 0,0 };
		sf::Vector2i animWalk_LEFT = { 0,0 };
		sf::Vector2i animWalk_RIGHT = { 0,16 };

		void camera(sf::RenderWindow& window);
};