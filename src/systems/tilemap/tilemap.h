#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Tilemap {
	public:
		Tilemap();
		void render(sf::RenderWindow&);

	private:
		const int TILE_SIZE = 16 * 4;
		const int WIDHT_MAX = 32;
		const int HEIGH_MAX = 32;

		sf::Texture grass_texture;
		sf::Sprite grass_sprite;

		void initilize();
};

