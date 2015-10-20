#pragma once

#include "Settings.h"

class SettingsWindow {
public:
	SettingsWindow() = default;
private:
	Settings generateSettingsFromUI();
};

