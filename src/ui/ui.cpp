#include "ui.hpp"

UI::UI() {
	if (!main_font.loadFromFile("../../../assets/fonts/arial.ttf")) return;

	ui_elements.push_back(
		std::move(
			gui.createLabel(
				"Hello, Miroro!", 
				main_font, 
				24, 
				sf::Color::White, 
				{ 25,25 }
			)
		)
	);
}

void UI::render(sf::RenderWindow& window) {
	for (const auto& element : ui_elements) {
		element->draw(window);
	}
}