#include "SettingsWindow.h"


using namespace GUI;

Core::Settings SettingsWindow::show() {
	return generateSettingsFromUI();
}

Core::Settings SettingsWindow::generateSettingsFromUI() {
	Core::Settings settings;
	settings.gridHeight = 10;
	settings.gridWidth = 10;

	settings.whoStarts = 1;
	settings.rowsToWin = 4;

	settings.playerNameA = "PlayerA";
	settings.playerNameB = "PlayerB";

	settings.gameType = Core::Settings::GameType::PlayerVSComputer;

	return settings;
}
