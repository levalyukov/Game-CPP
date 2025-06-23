#include "label.hpp"

Label::Label(
	std::string message,
	sf::Font* font,
	unsigned __int8 size,
	sf::Color color,
	sf::Vector2f coords_position,
	ElementPosition position,
	bool visible
) : message(message),
	font(*font),
	size(size),
	color(color),
	coords_pos(coords_position),
	position(position),
	isVisible(visible) {

	text.setFont(*font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(message);
	text.setPosition(coords_position);
}

void Label::setText(std::string new_string) {
	text.setString(new_string);
}

void Label::draw(sf::RenderWindow& window) const {
	window.draw(text);
}