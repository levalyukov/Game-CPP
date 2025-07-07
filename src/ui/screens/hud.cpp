#include "hud.hpp"

HUD::HUD(
	UI& uiManager
) : ui_ref(std::move(uiManager)) {

	loadAllFonts();
	createHUD();
} 

void HUD::loadAllFonts() {
	// test code
	resourceManager.loadFont("nunito", "../../../assets/fonts/nunito.ttf");
	resourceManager.loadFont("arial", "../../../assets/fonts/arial.ttf");
}

void HUD::createHUD() {
	
}