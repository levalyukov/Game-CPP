#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Entity {
	public:
		Entity(
			std::string name, 
			sf::Sprite& sprite, 
			sf::Vector2f position, 
			bool hasCollision
		);
		sf::Sprite getSprite();

	private:
		std::string m_name;
		sf::Sprite m_sprite;
		sf::Vector2f m_position;
		bool m_hasCollision;
};