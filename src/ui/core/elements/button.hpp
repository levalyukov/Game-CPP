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
		);
		
		void setAction(ButtonAction function);
		bool checkHover(sf::RenderWindow& window);

		void handleEvent(sf::Event& event, sf::RenderWindow& window);
		void draw(sf::RenderWindow& window) const;

	private:
		enum State {Normal, Hovered, Pressed};

		sf::Sprite m_sprite;
		sf::Texture* m_texture;
		sf::Vector2f m_position;
		ButtonAction m_action;
		State m_state;
		bool m_isPressed;

		void setState(State state);
};