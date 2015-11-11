#include "MainWindow.h"
#include <iostream>

using namespace GUI;

MainWindow::MainWindow() {
	controller = new Core::Controller();
	showMenu();
}

void MainWindow::showMenu() {
	std::cout << "Welcome!\nChoose an option:\n1. Start game\n2. Show help\n3. Show about\n3. Exit\n=";

	int option;
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		Core::Settings settings = showSettings();
		controller->startGame(settings);
		Core::Controller::State state = controller->getState();
		while (state == Core::Controller::State::Playing) {
			boardPanel.draw(controller->getBoard());
		}
		if (state == Core::Controller::State::GameOver) {

		}
		break;
	}
	case 2:
		showHelp();
		break;
	case 3:
		showAbout();
		break;
	case 4:
		exit(0);
		break;
	default:
		break;
	}

	system("cls");
	showMenu();
}

void MainWindow::showHelp(){
	help.show();
}

void MainWindow::showAbout(){
	about.show();
}

Core::Settings MainWindow::showSettings(){
	return settings.show();
}

void MainWindow::restartGame(){
	controller->restartGame();
}

void MainWindow::getMenuClick(){
}

MainWindow::~MainWindow() {
	delete controller;
}