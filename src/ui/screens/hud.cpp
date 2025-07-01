#include "hud.hpp"

HUD::HUD(
	UI& uiManager, 
	Economy& economyManager
) : ui_ref(std::move(uiManager)),
	economy_ref(std::move(economyManager)) {
	loadAllFonts();
	createHUD();
	update();
} 

void HUD::loadAllFonts() {
	ui_ref.addFont("nunito", "../../../assets/fonts/nunito.ttf");
}

void HUD::createHUD() {
	ui_ref.addElement(
		"SuperLabel",
		ui_ref.gui.createLabel(
			"Money: ...",
			ui_ref.getFont("nunito"),
			24,
			sf::Color::White,
			{ 25, 25 },
			UIElement::TopLeft
		)
	);
}

void HUD::update() {
	dynamic_cast<Label*>(ui_ref.getElement("SuperLabel"))->setText("Money: " + std::to_string(economy_ref.money));
}