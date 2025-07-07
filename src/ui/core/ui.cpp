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


void UI::render(sf::Event& event, sf::RenderWindow& window) {
	for (const auto& element : ui_elements) {
		element.second->handleEvent(event, window);
		element.second->draw(window);
	}
}