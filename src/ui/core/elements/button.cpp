#include "button.hpp"

Button::Button(
	sf::Texture* button_texture,
	sf::Vector2f coords_pos
) : m_texture(button_texture),
	m_position(coords_pos) {

	m_sprite.setTexture(*m_texture);
	m_sprite.setTextureRect(sf::IntRect(0,16,32,16));
	m_sprite.setPosition(m_position);
	m_sprite.scale(4, 4);
}

void Button::setAction(ButtonAction function) {
	m_action = function;
}

void Button::setState(State new_state) {
	m_state = new_state;
}

bool Button::checkHover(sf::RenderWindow& window) {
	return m_sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

void Button::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    bool isHovered = checkHover(window);
    switch (event.type) {
        case sf::Event::MouseMoved:
            if (!m_isPressed) m_state = isHovered ? Hovered : Normal;
            break;

        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left && isHovered) {
                m_state = Pressed;
                m_isPressed = true;
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left && m_isPressed) {
                if (isHovered && m_state == Pressed) m_action();
                m_state = isHovered ? Hovered : Normal;
                m_isPressed = false;
            }
            break;
    }
}

void Button::draw(sf::RenderWindow& window) const {
	window.draw(m_sprite);
}