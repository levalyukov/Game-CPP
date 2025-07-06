#include "ui.hpp"

// Manipulating objects
void UI::addElement(std::string name_element, std::unique_ptr<UIElement> element) {
	ui_elements.emplace(name_element, std::move(element));
}

UIElement* UI::getElement(std::string name_element) {
	auto element = ui_elements.find(name_element);
	return (element != ui_elements.end()) ? element->second.get() : nullptr;
}

void UI::removeElement(std::string name_element) {
	auto element = ui_elements.find(name_element);
	if (element != ui_elements.end()) {
		ui_elements.erase(name_element);
	}
}

// Fonts
void UI::addFont(std::string font_name, std::string path) {
	auto new_font = std::make_unique<sf::Font>();
	if (!new_font->loadFromFile(path)) return;
	fonts.emplace(std::move(font_name), std::move(new_font));
}

sf::Font* UI::getFont(std::string font_name) {
	auto current_font = fonts.find(font_name);
	return (current_font != fonts.end()) ? current_font->second.get() : nullptr;
}

void UI::removeFont(std::string font_name) {
	if (fonts.find(font_name) != fonts.end()) fonts.erase(font_name);
}


void UI::render(sf::Event& event, sf::RenderWindow& window) {
	for (const auto& element : ui_elements) {
		element.second->handleEvent(event, window);
		element.second->draw(window);
	}
}