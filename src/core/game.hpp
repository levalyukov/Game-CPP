#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../entities/player.hpp"
#include "../entities/entity-manager.hpp"
#include "../systems/tilemap/tilemap.hpp"
#include "../systems/ui/ui.hpp"

const std::string WINDOW_TITLE = "Delicious Soup";
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEGHT = 720;

class Game {
	public:
		Game();
		void run();

	private:
		void processEvent();
		void render();
		void initilizeIcon();

		sf::RenderWindow window;
		sf::Color background = sf::Color(85, 110, 74);
		sf::Event event;
		sf::Clock clock;
		sf::View gameView;
		sf::View uiView;

		// Game icon
		sf::Image icon;
		const sf::Uint8* pixelData;

		UI ui;
		Player player;
		Tilemap tilemap;
		EntityManager entityManager;

		float rawDelta = clock.restart().asSeconds();
		float deltaTime = std::min(rawDelta, 0.1f);
};