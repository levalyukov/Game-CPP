#include "Tilemap.h"

Tilemap::Tilemap() {
	initilize();
}

void Tilemap::initilize() {
	if (!rock_texture.loadFromFile("../../../assets/textures/location/tiles/rock.png")) return;
	if (!water_texture.loadFromFile("../../../assets/textures/location/tiles/water.png")) return;
	if (!grass_texture.loadFromFile("../../../assets/textures/location/tiles/grass.png")) return;

	rock_sprite.setTexture(rock_texture);
	water_sprite.setTexture(water_texture);
	grass_sprite.setTexture(grass_texture);

	rock_sprite.setScale(4, 4);
	water_sprite.setScale(4, 4);
	grass_sprite.setScale(4, 4);
}

void Tilemap::render(sf::RenderWindow& window) {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {

			if (x % 9 == 0) water_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (y % 9 == 0) water_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (x % 9 == 8) water_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (y % 9 == 8) water_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);

			else if (x % 9 == 2 && y >= 2 && y <= 6) rock_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (x % 9 == 6 && y >= 2 && y <= 6) rock_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (y % 9 == 2 && x >= 2 && x <= 6) rock_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			else if (y % 9 == 6 && x >= 2 && x <= 6) rock_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);

			else grass_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);

			window.draw(rock_sprite);
			window.draw(water_sprite);
			window.draw(grass_sprite);
		}
	}
}