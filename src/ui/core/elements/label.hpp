#pragma once

#include "ui-element.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Label : public UIElement {
	public:
		Label(
			std::string message,
			sf::Font* font,
			unsigned __int8 size,
			sf::Color color,
			sf::Vector2f coords_position,
			ElementPosition position
		) : message(message),
			font(*font),
			size(size),
			color(color),
			coords_pos(coords_position),
			position(position) {
			text.setFont(*font);
			text.setCharacterSize(size);
			text.setColor(color);
			text.setString(message);
			text.setPosition(coords_position);
		};

		inline void setText(std::string new_msg) { message = new_msg; text.setString(new_msg); };
		inline void setColor(sf::Color new_color) { color = new_color; text.setColor(color); };
		inline void setSize(unsigned __int8 new_size) { size = new_size; text.setCharacterSize(size); };

		inline void handleEvent(sf::Event& event, sf::RenderWindow& window) override {};
		inline void draw(sf::RenderWindow& window) const { window.draw(text); };

	private:
		std::string message;
		const sf::Font& font;
		unsigned __int8 size;
		sf::Text text;
		sf::Color color;
		sf::Vector2f coords_pos;
		ElementPosition position;
};