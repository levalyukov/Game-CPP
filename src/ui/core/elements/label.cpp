#include "label.hpp"

Label::Label(
	std::string name_element,
	std::string message,
	sf::Font* font,
	unsigned __int8 size,
	sf::Color color,
	sf::Vector2f position
) : name(name_element),
	message(message),
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

void Label::setText(std::string& new_string) {
	text.setString(new_string);
}

void Label::draw(sf::RenderWindow& window) const {
	window.draw(text);
}