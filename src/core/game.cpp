#include "game.h";

Game::Game() {
	window.create(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEGHT }), WINDOW_TITLE);
	window.setFramerateLimit(60);

	gameView = window.getDefaultView();
	uiView = window.getDefaultView();
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

		if (event.type == sf::Event::Resized) {
			gameView.setSize(event.size.width, event.size.height);
			uiView.setSize(event.size.width, event.size.height);
			uiView.setCenter(event.size.width / 2.f, event.size.height / 2.f);
		}
	}
}

void Game::render() {
	window.clear(background);

	// Game
	window.setView(gameView);
	tilemap.render(window);
	player.render(window, deltaTime, gameView);

	window.setView(uiView);
	ui.render(window);

	window.display();
}