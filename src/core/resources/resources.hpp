#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

class ResourceManager {
	public:
		static ResourceManager& Instance() {
			static ResourceManager r;
			return r;
		}

		// Textures
		void loadTexture(const std::string name, const std::string path);
		sf::Texture* getTexture(const std::string name);
		void removeTexture(const std::string name);

		// Fonts
		void loadFont(std::string font_name, std::string path);
		sf::Font* getFont(std::string font_name);
		void removeFont(std::string font_name);

	private:
		ResourceManager() {};
		~ResourceManager() {};

		ResourceManager(ResourceManager const&) = delete;
		ResourceManager& operator=(ResourceManager const&) = delete;

		std::map<std::string, std::unique_ptr<sf::Texture>> textures;
		std::map<std::string, std::unique_ptr<sf::Font>> fonts;
};