#include "game.h";

Game::Game() {
	window.create(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEGHT }), WINDOW_TITLE);
	window.setFramerateLimit(60);
	initilizeIcon();

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
	}
}

void Game::render() {
	window.clear(background);

	// Game
	window.setView(gameView);
	tilemap.render(window);
	player.render(window, deltaTime, gameView);

	window.setView(uiView);
	ui.render(window, uiView);

	window.display();
}

void Game::initilizeIcon() {
	if (!icon.loadFromFile("../../../assets/icon.png")) return;
	pixelData = icon.getPixelsPtr();
	window.setIcon(icon.getSize().x, icon.getSize().y, pixelData);
}