#include "gui.hpp"

std::unique_ptr<Label> GUI::createLabel(
	std::string message,
	sf::Font* font,
	unsigned __int8 size,
	sf::Color color,
	sf::Vector2f coords_pos,
	UIElement::ElementPosition position
) {
	return std::make_unique<Label>(message, font, size, color, coords_pos, position);
}

std::unique_ptr<Button> GUI::createButton(sf::Texture* texture, sf::Vector2f coords_pos) {
	return std::make_unique<Button>(texture, coords_pos);
}