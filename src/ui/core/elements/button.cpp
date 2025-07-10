#include "button.hpp"

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