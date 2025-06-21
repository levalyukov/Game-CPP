#pragma once

#include "gui/gui.hpp"
#include "gui/elements/ui-element.hpp"

#include <iostream>
#include <vector>

class UI {
	std::vector<std::unique_ptr<UIElement>> ui_elements;

	public:
		UI();

		void render(sf::RenderWindow& window);

		GUI gui;

		sf::Font main_font;
};