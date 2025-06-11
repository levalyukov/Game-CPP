#include "Tilemap.h"

Tilemap::Tilemap() {
	initilize();
}

void Tilemap::initilize() {
	if (!grass_texture.loadFromFile("../../../assets/Textures/World/grass.png")) return;

	grass_sprite.setTexture(grass_texture);
	grass_sprite.setScale(4, 4);
}

void Tilemap::render(sf::RenderWindow& window) {
	for (int x = 0; x < WIDHT_MAX; x++) {
		for (int y = 0; y < HEIGH_MAX; y++) {
			grass_sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
			window.draw(grass_sprite);
		}
	}
}