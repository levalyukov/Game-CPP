#pragma once

#include "../core/ui.hpp"

#include <iostream>

class HUD {
	public:
		HUD(UI& ui);

		void loadAllFonts();
		void createHUD();

	private:
		UI& ui_ref;

	protected:
};