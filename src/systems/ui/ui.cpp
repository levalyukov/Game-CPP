#include "ui.hpp"

UI::UI() {
	initilize(font);
}

void UI::render(sf::RenderWindow& window, sf::View& uiView) {
	coins.setString("Coins: " + std::to_string(economy.money));

	window.draw(coins);

	ui = uiView;
}

void UI::initilize(sf::Font& font) {
	if (!font.loadFromFile("../../../assets/fonts/arial.ttf")) return;

	createHUD();
}

void UI::setElementPosition(Alignment alignment, sf::Text& ui_label, float offsetX, float offsetY)  {
	sf::FloatRect bounds = ui_label.getLocalBounds();
	sf::Vector2f viewSize = ui.getSize();

	switch (alignment) {
		case TopLeft:
			ui_label.setPosition(offsetX, offsetY);
			break;
	}
}

void UI::createHUD() {
	coins.setCharacterSize(26);
	coins.setFont(font);
	coins.setPosition(10.f, 10.f);
	setElementPosition(TopLeft, coins, 10.0f, 10.0f);
}