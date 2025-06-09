#include "ui.h"

UI::UI() {
	initilize(font);
}

void UI::render(sf::RenderWindow& window) {
	window.draw(test_text);
}

void UI::initilize(sf::Font& font) {
	if (!font.loadFromFile("../../../assets/fonts/arial.ttf")) {
		std::cout << "Error: 'arial.ttf' not loaded." << std::endl;
		return;
	}
	test_text.setString("UI Text");
	test_text.setCharacterSize(50);
	test_text.setFont(font);
	test_text.setPosition(10.f, 10.f);
}