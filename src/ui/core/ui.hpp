#pragma once

#include "gui.hpp"
#include "elements/ui-element.hpp"

#include <iostream>

class UIManager {
	public:
		static UIManager& Instance() {
			static UIManager r;
			return r;
		}

		inline void addElement(std::string name_element, std::unique_ptr<UIElement> element) {
			ui_elements.emplace(name_element, std::move(element));
		};

		inline UIElement* getElement(std::string name_element) {
			auto element = ui_elements.find(name_element);
			return (element != ui_elements.end()) ? element->second.get() : nullptr;
		};

		inline void removeElement(std::string name_element) {
			auto element = ui_elements.find(name_element);
			if (element != ui_elements.end()) {
				ui_elements.erase(name_element);
			}
		};

		inline void render(sf::Event& event, sf::RenderWindow& window) {
			for (const auto& element : ui_elements) {
				element.second->handleEvent(event, window);
				element.second->draw(window);
			}
		};

		GUI gui;

	private:
		UIManager() {};
		~UIManager() {};

		UIManager(UIManager const&) = delete;
		UIManager& operator=(UIManager const&) = delete;

		std::map<std::string, std::unique_ptr<UIElement>> ui_elements;
};