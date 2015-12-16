#include "SettingsWindow.h"
#include <iostream>

Settings SettingsWindow::show() {
	return generateSettingsFromUI();
}

Settings SettingsWindow::generateSettingsFromUI() {
	Settings settings;

	settings.gridHeight = 10;
	settings.gridWidth = 10;

	settings.whoStarts = 1;
	settings.rowsToWin = 4;

	settings.playerNameA = "PlayerA";
	settings.playerNameB = "PlayerB";

	std::cout << "Choose mode:\n1.PvP\n2.PvC\n3.PvR\n";

	int option;
	
	std::cin >> option;
		
	switch (option)
	{
	case 1:
		settings.gameType = Settings::GameType::PlayerVSPlayer;
		break;
	case 2:
		settings.gameType = Settings::GameType::PlayerVSComputer;
		break;
	case 3:
		settings.gameType = Settings::GameType::PlayerVSComputer;
		break;
	default:
		settings.gameType = Settings::GameType::PlayerVSRemote;
		break;
	}

	return settings;
}
