#pragma once

#include "Settings.h"

namespace GUI {
	
	/*
	Generating a Settings object containing the game data the user specified.
	*/
	class SettingsWindow {
	public:
		SettingsWindow() = default;
	private:
		Core::Settings generateSettingsFromUI();
	};
}

