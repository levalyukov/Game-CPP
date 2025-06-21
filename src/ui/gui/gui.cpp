#include "gui.hpp"

std::unique_ptr<Label> GUI::createLabel(
	std::string message,
	sf::Font& font,
	unsigned int size,
	sf::Color color,
	sf::Vector2f position
) {
	return std::make_unique<Label>(message, font, size, color, position);
}