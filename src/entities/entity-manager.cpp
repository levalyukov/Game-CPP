#include "entity-manager.hpp"
#include "entity.hpp"

void EntityManager::addEntity(std::string name, sf::Sprite& sprite, sf::Vector2f position, bool hasCollision) {
	int id = nextID++;
	entities.emplace(id, std::move(std::make_unique<Entity>(name, sprite, position, hasCollision)));
}

Entity* EntityManager::getEntity(int id) {
	auto entity = entities.find(id);
	return (entity != entities.end()) ? entity->second.get() : nullptr;
}

void EntityManager::removeEntity(int id) {
	if (entities.find(id) != entities.end()) entities.erase(id);
}

void EntityManager::render(sf::RenderWindow& window) {
	if (entities.empty()) return;

	for (auto& object : entities) {
		window.draw(object.second->getSprite());
	}
}