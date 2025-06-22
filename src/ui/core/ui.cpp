#include "ui.hpp"

UI::UI() {
	addFont("nunito", "../../../assets/fonts/nunito.ttf");
	addElement(
		gui.createLabel(
			"label_123",
			"Game Menu",
			getFont("nunito"),
			36,
			sf::Color::White,
			{25, 25}
		)
	);
}

void UI::addElement(std::unique_ptr<UIElement> element) {
	ui_elements.push_back(std::move(element));
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

void UI::render(sf::RenderWindow& window) {
	for (const auto& element : ui_elements) {
		element->draw(window);
	}
}