#include "label.hpp"

Label::Label(
	std::string message,
	sf::Font* font,
	unsigned int size,
	sf::Color color,
	sf::Vector2f position
) : message(message),
	font(*font),
	size(size),
	color(color),
	position(position) {

	text.setFont(*font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(message);
	text.setPosition(position);

}

void Label::draw(sf::RenderWindow& window) const {
	window.draw(text);
}