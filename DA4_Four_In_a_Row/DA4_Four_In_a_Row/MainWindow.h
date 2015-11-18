#pragma once

#include "BoardPanel.h"
#include "HelpWindow.h"
#include "AboutWindow.h"
#include "Controller.h"
#include "SettingsWindow.h"
#include "Settings.h"
#include "IBoardUpdateCallback.h"

namespace GUI {
	/*
	Is a GUI container for frame, status bar and menu.
	*/
	class MainWindow : public Core::IBoardUpdateCallback {
	public:
		MainWindow();

		~MainWindow();

	private:
		void showMenu();
		void showHelp();
		void showAbout();

		Core::Settings showSettings();
		void restartGame();

		virtual void onBoardUpdate() override;

		void getMenuClick();

		BoardPanel boardPanel;
		Core::Controller* controller;

		char statusBar;
		SettingsWindow settings;
		HelpWindow help;
		AboutWindow about;
	};
}

