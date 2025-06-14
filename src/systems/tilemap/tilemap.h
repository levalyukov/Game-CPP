#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Tilemap {
	public:
		Tilemap();
		void render(sf::RenderWindow& window);

	private:
		const int TILE_SIZE = 64;
		const int WIDHT_MAX = 32;
		const int HEIGH_MAX = 32;

		sf::Texture rock_texture;
		sf::Texture water_texture;
		sf::Texture grass_texture;
		sf::Sprite rock_sprite;
		sf::Sprite water_sprite;
		sf::Sprite grass_sprite;

		void initilize();
};

