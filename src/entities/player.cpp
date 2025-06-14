#include "player.h"

Player::Player() {
	if (!texture_idle.loadFromFile("../../../assets/textures/entity/player/character_idle.png")) return;
	if (!texture_walk_horizontal.loadFromFile("../../../assets/textures/entity/player/character_walk_horizontal.png")) return;
	if (!texture_walk_vertical.loadFromFile("../../../assets/textures/entity/player/character_walk_vertical.png")) return;

	sprite.setTexture(texture_idle);
	sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	sprite.setPosition((9 / 2) * 64, 64*6);
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

		oldVectorUP	= vectorUP;
		oldVectorDOWN = vectorDOWN;
		oldVectorLEFT = vectorLEFT;
		oldVectorRIGHT = vectorRIGHT;
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
			animations.setAnimation(
				sprite,
				target_texture,
				oldVectorUP,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "down") {
			animations.setAnimation(
				sprite,
				target_texture,
				oldVectorDOWN,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "left") {
			animations.setAnimation(
				sprite,
				target_texture,
				oldVectorLEFT,
				2, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}

		if (currentDirection == "right") {
			animations.setAnimation(
				sprite,
				target_texture,
				oldVectorRIGHT,
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
			oldVectorUP = vectorUP;
		}
		if (currentDirection == "down") {
			sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
			oldVectorDOWN = vectorDOWN;
		}
		if (currentDirection == "left") {
			sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
			oldVectorLEFT = vectorLEFT;
		}
		if (currentDirection == "right") {
			sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
			oldVectorRIGHT = vectorRIGHT;
		}
	}
}