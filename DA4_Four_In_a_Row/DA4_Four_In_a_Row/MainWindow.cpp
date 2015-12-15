#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow() : help(new HelpWindow), about(new AboutWindow), settings(new SettingsWindow) {
	controller = new Controller(static_cast<IBoardUpdateCallback*>(this));
	showMenu();
}

void MainWindow::showMenu() {
	system( "cls" );
	std::cout << "Welcome!\nChoose an option:\n1. Start game\n2. Show help\n3. Show about\n0. Exit\n=";

	int option;
	std::cin >> option;

	switch (option)
	{
	case 1:
		startGame();
		break;
	case 2:
		showHelp();
		break;
	case 3:
		showAbout();
		break;
	case 0:
		exitProcess();
		break;
	default:
		break;
	}
	
	showMenu();
}

void MainWindow::onBoardUpdate() {
	boardPanel->draw(controller->getBoard());
}

void MainWindow::startGame() {
	system( "cls" );

	Settings settings = showSettings();
	controller->setupNewGame(settings);

	// draw init board
	boardPanel->draw( controller->getBoard() );

	// Main game
	controller->startGame();

	onBoardUpdate();

	// When game is done. Exit the current game
	controller->exitGame();


	// Check end game reason
	Controller::State state = controller->getState();
	if ( state == Controller::State::GameOver ) {
		system( "cls" );
		std::cout << "Game Over!\n\n1. Restart\n2. Main menu\n";
		int option;
		std::cin >> option;

		if ( option == 1 ) {
			restartGame();
		} else {
			// Do nothing
		}
	} else if ( state == Controller::State::Exit ) {
		// also do nothing
	}
}

void MainWindow::showHelp(){
	help->show();
}

void MainWindow::showAbout(){
	about->show();
}

Settings MainWindow::showSettings(){
	return settings->show();
}

void MainWindow::restartGame(){
	startGame();
}

void MainWindow::getMenuClick(){
}

void MainWindow::exitProcess() {
	exit(0);
}

MainWindow::~MainWindow() {
	delete controller;
	delete help;
	delete about;
	delete settings;
}