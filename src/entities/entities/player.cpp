#include "player.hpp"

Player::Player(
	sf::Texture* character_idle,
	sf::Texture* character_walk_horizontal,
	sf::Texture* character_walk_vertical
) : idle(std::move(*character_idle)),
	walkHorizontal(std::move(*character_walk_horizontal)),
	walkVertical(std::move(*character_walk_vertical)) {
	sprite.setTexture(idle);
	sprite.setTextureRect(sf::IntRect(16, 0, spriteSizeX.x, spriteSizeX.y));
	sprite.setPosition((9 / 2) * 64, (9/2) * 64);
	sprite.setScale(4, 4);
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
		float animationSpeed = (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) ? RUN_ANIM : WALK_ANIM;
		sf::Texture& target_texture = (currentDirection == "up" || currentDirection == "down") ? walkVertical : walkHorizontal;

		if (currentDirection == "up") {
			animations.setAnimation(
				sprite,
				target_texture,
				oldVectorUP,
				4, 16, 16,
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
				4, 16, 16,
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
				4, 16, 16,
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
				4, 16, 16,
				animationTimer,
				animationSpeed,
				deltaTime
			);
		}
	}
	else {
		sprite.setTexture(idle);
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