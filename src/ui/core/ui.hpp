#pragma once

#include "gui.hpp"
#include "elements/ui-element.hpp"

#include <iostream>

class UI {
	public:
		std::map<std::string, std::unique_ptr<UIElement>> ui_elements;

		// Elements
		void addElement(std::string name_element, std::unique_ptr<UIElement> element);
		UIElement* getElement(std::string name_element);
		void removeElement(std::string name_element);

		void render(sf::Event& event, sf::RenderWindow& window);

		GUI gui;
};