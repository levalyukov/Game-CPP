#include "entity.hpp"

Entity::Entity(
	std::string name,
	sf::Sprite& sprite,
	sf::Vector2f position,
	bool hasCollision
) : m_name(std::move(name)),
	m_sprite(std::move(sprite)),
	m_position(position),
	m_hasCollision(hasCollision) {
	m_sprite.setPosition(m_position);
}

sf::Sprite Entity::getSprite() const { return m_sprite; }

