#include "ui.h"

UI::UI() {
	initilize(font);
}

void UI::render(sf::RenderWindow& window, sf::View& uiView) {
	window.draw(test_text);
	ui = uiView;
}

void UI::initilize(sf::Font& font) {
	if (!font.loadFromFile("../../../assets/fonts/arial.ttf")) {
		std::cout << "Error: 'arial.ttf' not loaded." << std::endl;
		return;
	}

	createHUD();
}

void UI::setTextPosition(Alignment alignment, sf::Text& ui_label, float offsetX, float offsetY)  {
	sf::FloatRect bounds = ui_label.getLocalBounds();
	sf::Vector2f viewSize = ui.getSize();

	switch (alignment) {
		case TopLeft:
			ui_label.setPosition(offsetX, offsetY);
			break;
	}
}

void UI::createHUD() {
	test_text.setString("UI Text");
	test_text.setCharacterSize(36);
	test_text.setFont(font);
	test_text.setPosition(10.f, 10.f);
	setTextPosition(TopLeft, test_text, 10.0f, 10.0f);
}