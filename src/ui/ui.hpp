#pragma once

#include "gui/gui.hpp"
#include "gui/elements/ui-element.hpp"

#include <iostream>
#include <vector>

class UI {
	std::map<std::string, std::unique_ptr<sf::Font>> fonts;
	std::vector<std::unique_ptr<UIElement>> ui_elements;

	public:
		UI();

		void addFont(std::string font_name, std::string path);
		sf::Font* getFont(std::string font_name);

		void render(sf::RenderWindow& window);

		GUI gui;
};