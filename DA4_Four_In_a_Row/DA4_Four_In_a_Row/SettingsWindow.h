#pragma once

#include "Settings.h"

	
	/*
	Generating a Settings object containing the game data the user specified.
	*/
	class SettingsWindow {
	public:
		SettingsWindow() = default;
		Settings show();
	private:
		Settings generateSettingsFromUI();
	};

