#pragma once

#include "Settings.h"

/*
Generating a Settings object containing the game data the user specified.
*/
class SettingsWindow {
public:
	SettingsWindow() = default;

	/*
	@return the user generated setting
	*/
	Settings show();
private:

	/*
	@return the user generated setting
	*/
	Settings generateSettingsFromUI();
};

