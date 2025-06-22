#include "gui.hpp"

std::unique_ptr<Label> GUI::createLabel(
	std::string message,
	sf::Font* font,
	unsigned __int8 size,
	sf::Color color,
	sf::Vector2f coords_pos,
	UIElement::ElementPosition position,
	bool visible
) {
	return std::make_unique<Label>(message, font, size, color, coords_pos, position, visible);
}