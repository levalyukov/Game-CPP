#include "game.h";

Game::Game() {
	window.create(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEGHT }), WINDOW_TITLE);
	window.setFramerateLimit(60);
}

void Game::run() {
	while (window.isOpen()) {
		processEvent();
		render();
	}
}

void Game::processEvent() {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Game::render() {
	window.clear(background);

	// Game
	tilemap.render(window);
	player.render(window, deltaTime);
	window.setView(window.getDefaultView());
	ui.render(window);

	window.display();
}