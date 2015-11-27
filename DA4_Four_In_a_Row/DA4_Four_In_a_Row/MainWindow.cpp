#include "MainWindow.h"
#include <iostream>



MainWindow::MainWindow() {
	controller = new Controller(dynamic_cast<IBoardUpdateCallback*>(this));
	showMenu();
}

void MainWindow::showMenu() {
	std::cout << "Welcome!\nChoose an option:\n1. Start game\n2. Show help\n3. Show about\n0. Exit\n=";

	int option;
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		Settings settings = showSettings();
		
		controller->setupNewGame(settings);
		
		// Draw initial board
		onBoardUpdate();

		controller->startGame();

		// Clean up
		controller->exitGame();
		
		//	while (state == Controller::State::Playing) {
			
		//}
		//if (state == Controller::State::GameOver) {

		//}
		break;
	}
	case 2:
		showHelp();
		break;
	case 3:
		showAbout();
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}

	system("cls");
	showMenu();
}

void MainWindow::onBoardUpdate() {
	boardPanel.draw(controller->getBoard());

	Controller::State state = controller->getState();
	if (state == Controller::State::GameOver) {
		
		//system("cls");
		std::cout << "Game Over!\n\n1. Restart\n2. Main menu\n";
		int option;
		std::cin >> option;
		if (option == 1) {
			controller->restartGame();
		}
	}
}

void MainWindow::showHelp(){
	help.show();
}

void MainWindow::showAbout(){
	about.show();
}

Settings MainWindow::showSettings(){
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