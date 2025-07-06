#pragma once

#include "gui.hpp"
#include "elements/ui-element.hpp"

#include <iostream>
#include <vector>

class UI {
	public:
		std::map<std::string, std::unique_ptr<sf::Font>> fonts;
		std::map<std::string, std::unique_ptr<UIElement>> ui_elements;

		// Elements
		void addElement(std::string name_element, std::unique_ptr<UIElement> element);
		UIElement* getElement(std::string name_element);
		void removeElement(std::string name_element);
		
		// Fonts
		void addFont(std::string font_name, std::string path);
		sf::Font* getFont(std::string font_name);
		void UI::removeFont(std::string font_name);

		void render(sf::Event& event, sf::RenderWindow& window);

		GUI gui;
};