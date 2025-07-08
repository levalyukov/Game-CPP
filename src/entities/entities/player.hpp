#pragma once

#include "../entity.hpp"
#include "../../core/animations/animations.hpp"

#include <SFML/Graphics.hpp>

class Player : public Entity {
	public:
		Player(
			sf::Texture* character_idle,
			sf::Texture* character_walk_horizontal,
			sf::Texture* character_walk_vertical
		);

		void movement(float deltaTime);
		void render(sf::RenderWindow& window, float deltaTime, sf::View& gameCamera);

	private:
		sf::Sprite sprite;
		sf::Texture idle;
		sf::Texture walkHorizontal;
		sf::Texture walkVertical;
		sf::Vector2i spriteSizeX {16,16};
		const float RUN_SPEED = 6.0f;
		const float WALK_SPEED = 4.0f;

		Animations animations;

		std::string direction;
		std::string currentDirection;
		std::string oldDirection;

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