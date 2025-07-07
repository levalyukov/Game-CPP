#pragma once

#include "../entities/player.hpp"
#include "../entities/entity-manager.hpp"

#include "../economy/economy.hpp"

#include "../ui/core/ui.hpp"
#include "../ui/screens/hud.hpp"

#include "tilemap/tilemap.hpp"
#include "debug/debug.hpp"

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

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

		UI uiManager;
		Economy economyManager;
		HUD hud{ uiManager };
		Player player;
		Tilemap tilemap;
		EntityManager entityManager;

		float rawDelta = clock.restart().asSeconds();
		float deltaTime = std::min(rawDelta, 0.1f);
};