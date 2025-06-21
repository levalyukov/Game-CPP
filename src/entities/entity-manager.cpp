#include "entity-manager.hpp"
#include "entity.hpp"

EntityManager::EntityManager() {
	if (!cashDeskTexture.loadFromFile("../../../assets/textures/location/decor/test_obj.png")) return;
	cashDeskSprite.setTexture(cashDeskTexture);
	cashDeskSprite.setScale(4, 4);

	addEntity(
		"test_obj",
		cashDeskSprite,
		{ 64 * 2, 64 },
		false
	);
}

void EntityManager::addEntity(
	std::string name,
	sf::Sprite& sprite,
	sf::Vector2f position,
	bool hasCollision
) {
	int id = nextID++;
	entities.emplace(
		id, 
		Entity(
			name, 
			sprite, 
			position, 
			hasCollision
		)
	);
}

Entity* EntityManager::getEntity(int id) {
	auto entity = entities.find(id);
	return (entity != entities.end()) ? &entity->second : nullptr;
}

void EntityManager::removeEntity(int id) {
	if (entities.find(id) != entities.end()) entities.erase(id);
}

void EntityManager::render(sf::RenderWindow& window) {
	if (entities.empty()) return;

	for (const auto& object : entities) {
		const Entity& entity = object.second;
		window.draw(entity.getSprite());
	}
}