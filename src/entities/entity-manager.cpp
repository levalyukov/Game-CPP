#include "entity-manager.h"
#include "entity.h"

EntityManager::EntityManager() {
	if (!cafeTexture.loadFromFile("../../../assets/textures/location/decor/kitchen.png")) return;
	cafeSprite.setTexture(cafeTexture);
	cafeSprite.setScale(4, 4);

	addEntity(
		"cafe",
		cafeSprite,
		{ 128,128 },
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
	auto it = entities.find(id);
	return (it != entities.end()) ? &it->second : nullptr;
}

void EntityManager::removeEntity(int id) {
	if (entities.find(id) == entities.end()) {
		std::cerr << "Error: entity with the ID was not found." << std::endl;
		return;
	}

	entities.erase(id);
}

void EntityManager::render(sf::RenderWindow& window) {
	if (entities.empty()) return;

	for (const auto& object : entities) {
		const Entity& entity = object.second;
		window.draw(entity.getSprite());
	}
}