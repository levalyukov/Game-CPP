#pragma once

#include "entity.h"

#include <map>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class EntityManager {
	public:
		std::map <int, Entity> entities;
		int nextID = 0;

		EntityManager();

		void addEntity(
			std::string name, 
			sf::Sprite& sprite, 
			sf::Vector2f position, 
			bool hasCollision
		);
		Entity* getEntity(int id);
		void removeEntity(int enitityID);
		
		void render(sf::RenderWindow& window);

	private:
		sf::Sprite cafeSprite;
		sf::Texture cafeTexture;
		
};