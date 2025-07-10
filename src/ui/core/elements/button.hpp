#pragma once

#include "ui-element.hpp"

#include <iostream>
#include <functional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button : public UIElement {
	public:
		using ButtonAction = std::function<void()>;

		Button(
			sf::Texture* button_texture,
			sf::Vector2f coords_pos
		) : m_texture(button_texture),
			m_position(coords_pos) {
			m_sprite.setTexture(*m_texture);
			m_sprite.setTextureRect(sf::IntRect(0, 16, 32, 16));
			m_sprite.setPosition(m_position);
			m_sprite.scale(4, 4);
		};

		void setAction(ButtonAction function) { m_action = function; };
		bool checkHover(sf::RenderWindow& window) { return m_sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))); };

		void handleEvent(sf::Event& event, sf::RenderWindow& window);
		void draw(sf::RenderWindow& window) const { window.draw(m_sprite); };

	private:
		enum State {Normal, Hovered, Pressed};

		sf::Sprite m_sprite;
		sf::Texture* m_texture;
		sf::Vector2f m_position;
		ButtonAction m_action;
		State m_state;
		bool m_isPressed;

		void setState(State new_state) { m_state = new_state; };
};