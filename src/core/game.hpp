#pragma once

#include "tilemap/tilemap.hpp"
#include "resources/resources.hpp"

#include "../entities/entity-manager.hpp"
#include "../ui/core/ui.hpp"
#include "../ui/screens/hud.hpp"
#include "../entities/entities/player.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

class Game {
	public:
		Game();
		void run();

	private:
		const std::string WINDOW_TITLE = "Delicious Soup";
		unsigned int WINDOW_WIDTH = 1280;
		unsigned int WINDOW_HEGHT = 720;

		sf::RenderWindow window;
		sf::Color background = sf::Color(85, 110, 74);
		sf::Event event;
		sf::Clock clock;
		sf::View gameView;
		sf::View UIView;

		void processEvent();
		void render();
		void initilizeIcon();

		ResourceManager& resourceManager = ResourceManager::Instance();
		UI uiManager;
		Tilemap tilemap;
		EntityManager entityManager;
		HUD hud{uiManager};

		sf::Image icon;
		const sf::Uint8* iconData;

		float rawDelta = clock.restart().asSeconds();
		float deltaTime = std::min(rawDelta, 0.1f);
};