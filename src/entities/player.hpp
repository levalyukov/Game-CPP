#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "../core/animations/animations.hpp"

class Player {
	public:
		Player();
		void render(sf::RenderWindow& window, float deltaTime, sf::View& gameView);
		void movement(float deltaTime);

	private:
		// Player sprite
		sf::Sprite sprite;
		sf::Texture texture_walk_vertical;
		sf::Texture texture_walk_horizontal;
		sf::Texture texture_idle;
		sf::View view;

		// Animations
		Animations animations;

		std::string direction;
		std::string currentDirection;
		std::string oldDirection;

		const float RUN_SPEED = 6.0f;
		const float WALK_SPEED = 4.0f;

		const float RUN_ANIM = 0.10f;
		const float WALK_ANIM = 0.15f;

		int currentFrame = 0;
		float animationTimer = 0.0f;

		sf::Vector2i vectorUP = { 0,16 };
		sf::Vector2i vectorDOWN = { 0,0 };
		sf::Vector2i vectorLEFT = { 0,0 };
		sf::Vector2i vectorRIGHT = { 0,16 };

		sf::Vector2i oldVectorUP;
		sf::Vector2i oldVectorDOWN;
		sf::Vector2i oldVectorLEFT;
		sf::Vector2i oldVectorRIGHT;
};