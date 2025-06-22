#include "gui.hpp"

std::unique_ptr<Label> GUI::createLabel(
	std::string name_element,
	std::string message,
	sf::Font* font,
	unsigned __int8 size,
	sf::Color color,
	sf::Vector2f position
) {
	return std::make_unique<Label>(name_element, message, font, size, color, position);
}