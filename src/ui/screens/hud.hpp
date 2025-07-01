#pragma once

#include "../core/ui.hpp"
#include "../../economy/economy.hpp"

#include "pause.hpp"

#include <iostream>

class HUD {
	public:
		HUD(UI& uiManager, Economy& economyManager);

		void loadAllFonts();
		void createHUD();
		void update();

	private:
		UI& ui_ref;
		Economy& economy_ref;
		PauseMenu pause{ ui_ref };
};