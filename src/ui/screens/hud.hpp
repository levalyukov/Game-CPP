#pragma once

#include "../../core/resources/resources.hpp"
#include "../core/ui.hpp"

#include <iostream>

class HUD {
	public:
		HUD(UI& uiManager);

		void loadAllFonts();
		void createHUD();

	private:
		UI& ui_ref;
		ResourceManager& resourceManager = ResourceManager::Instance();
};