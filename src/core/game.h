#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../entities/player.h"
#include "../systems/tilemap/tilemap.h"

const std::string WINDOW_TITLE = "Simple Game";
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEGHT = 720;

class Game {
public:
	Game();
	void run();

private:
	void processEvent();
	void render();

	sf::RenderWindow window;
	sf::Color background = sf::Color(213, 11, 111);
	sf::Event event;
	sf::Clock clock;

	Player player;
	Tilemap tilemap;

	float deltaTime = clock.restart().asSeconds();
};