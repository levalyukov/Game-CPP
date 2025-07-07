#include "resources.hpp"

// Textures
void ResourceManager::loadTexture(const std::string name, const std::string path) {
	auto texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(path)) return;
	textures.emplace(name,std::move(texture));
}

sf::Texture* ResourceManager::getTexture(const std::string name) {
	auto element = textures.find(name);
	return (element != textures.end()) ? element->second.get() : nullptr;
}

void ResourceManager::removeTexture(const std::string name) {
	auto element = textures.find(name);
	if (element != textures.end()) textures.erase(name);
}

// Fonts
void ResourceManager::loadFont(std::string font_name, std::string path) {
	auto new_font = std::make_unique<sf::Font>();
	if (!new_font->loadFromFile(path)) return;
	fonts.emplace(std::move(font_name), std::move(new_font));
}

sf::Font* ResourceManager::getFont(std::string font_name) {
	auto current_font = fonts.find(font_name);
	return (current_font != fonts.end()) ? current_font->second.get() : nullptr;
}

void ResourceManager::removeFont(std::string font_name) {
	if (fonts.find(font_name) != fonts.end()) fonts.erase(font_name);
}