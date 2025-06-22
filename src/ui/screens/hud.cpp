#include "hud.hpp"

HUD::HUD(UI& ui) : ui_ref(ui) {
	loadAllFonts();
	createHUD();
} 

void HUD::loadAllFonts() {
	ui_ref.addFont("nunito", "../../../assets/fonts/nunito.ttf");
}

void HUD::createHUD() {
	ui_ref.addElement(
		"SuperLabel",
		ui_ref.gui.createLabel(
			"Money: ---",
			ui_ref.getFont("nunito"),
			24,
			sf::Color::White,
			{ 25, 25 },
			UIElement::TopLeft,
			true
		)
	);
}