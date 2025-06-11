#include "player.h"

std::string currentDirection = "down";

int currentFrame = 0;
float animationTimer = 0.0f;

sf::Vector2i walk_UP;
sf::Vector2i walk_DOWN;
sf::Vector2i walk_LEFT;
sf::Vector2i walk_RIGHT;

static std::string oldDirection = "";

Player::Player() {
	if (!texture_idle.loadFromFile("../../../assets/Textures/character_idle.png")) return;
	if (!texture_walk_horizontal.loadFromFile("../../../assets/Textures/character_walk_horizontal.png")) return;
	if (!texture_walk_vertical.loadFromFile("../../../assets/Textures/character_walk_vertical.png")) return;

	sprite.setTexture(texture_idle);
	sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	sprite.setScale(4, 4);
	view.setSize({ 1280,720 });
}

void Player::render(sf::RenderWindow& window, float deltaTime, sf::View& gameView) {
	window.draw(sprite);
	movement(deltaTime);
	gameView.setCenter(sprite.getPosition());
}

void Player::movement(float deltaTime) {
	bool movementUp = false;
	bool movementDown = false;
	bool movementLeft = false;
	bool movementRight = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movementUp = true;
		direction = "up";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movementLeft = true;
		direction = "left";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movementDown = true;
		direction = "down";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movementRight = true;
		direction = "right";
	}

	std::string newDirection = direction;

	if (newDirection != currentDirection) {
		currentFrame = 0;
		animationTimer = 0.0f;
		currentDirection = newDirection;
		walk_UP = animWalk_UP;
		walk_DOWN = animWalk_DOWN;
		walk_LEFT = animWalk_LEFT;
		walk_RIGHT = animWalk_RIGHT;
	}

	// Movement
	float speed = (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) ? RUN_SPEED : WALK_SPEED;
	if (movementUp && !movementDown) sprite.move(0.0, -speed);
	if (movementDown && !movementUp) sprite.move(0.0, speed);
	if (movementLeft && !movementRight) sprite.move(-speed, 0.0);
	if (movementRight && !movementLeft) sprite.move(speed, 0.0);

	bool isMoving = (movementUp || movementDown || movementLeft || movementRight);

	// Animation play
	if (isMoving) {
		float animationSpeed = (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) ? .15f : .25f;
		sf::Texture& target_texture = (currentDirection == "up" || currentDirection == "down") ? texture_walk_vertical : texture_walk_horizontal;

		if (currentDirection == "up") {
			animations.UpdateAnimation(
				sprite,
				target_texture,
				walk_UP,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "down") {
			animations.UpdateAnimation(
				sprite,
				target_texture,
				walk_DOWN,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "left") {
			animations.UpdateAnimation(
				sprite,
				target_texture,
				walk_LEFT,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "right") {
			animations.UpdateAnimation(
				sprite,
				target_texture,
				walk_RIGHT,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}
	}
	else {
		sprite.setTexture(texture_idle);
		if (currentDirection == "up") {
			sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
			walk_UP = animWalk_UP;
		}
		if (currentDirection == "down") {
			sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
			walk_DOWN = animWalk_DOWN;
		}
		if (currentDirection == "left") {
			sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
			walk_LEFT = animWalk_LEFT;
		}
		if (currentDirection == "right") {
			sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
			walk_RIGHT = animWalk_RIGHT;
		}
	}
}