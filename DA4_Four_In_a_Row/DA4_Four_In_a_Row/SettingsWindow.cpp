#include "SettingsWindow.h"


using namespace GUI;

Core::Settings SettingsWindow::show() {
	return generateSettingsFromUI();
}

Core::Settings SettingsWindow::generateSettingsFromUI() {
	Core::Settings settings;
	settings.gridHeight = 10;
	settings.gridWidth = 10;

	return settings;
}
