#pragma once

#include "BoardPanel.h"
#include "HelpWindow.h"
#include "AboutWindow.h"
#include "Controller.h"
#include "SettingsWindow.h"

class MainWindow {
public:
	MainWindow();
private:
	void showHelp();
	void showAbout();
	void showSettings();
	void restartGame();

	void getMenuClick();

	BoardPanel boardPanel;
	Controller controller;
	char statusBar;
	
	SettingsWindow settings;
	HelpWindow help;
	AboutWindow about;
};

