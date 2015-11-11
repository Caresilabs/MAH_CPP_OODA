#include "Controller.h"
#include "PlayerManager.h"

using namespace Core;

Controller::Controller() {
}

void Controller::startGame(Settings settings) {
	state = Playing;
	playerManager = new PlayerManager(this, settings);
	board = new Board(settings.gridWidth, settings.gridHeight);
	playerManager->start();
}

void Controller::restartGame() {
	delete playerManager;
	delete board;

	// TODO
	startGame(Settings());
}

void Controller::exitGame() {
	state = Exit;
}

/*
Inserts a piece on the board.
@param player id who want to insert.
@param the x position on the board
@return if the move was valid
*/
bool Controller::makeMove(int player, int x) {
	Board::State state = board->insert(player, x);
	switch (state)
	{
	case Core::Board::Full:
		return true;
	case Core::Board::Invalid:
		return false;
	case Core::Board::Win:
		return true;
	case Core::Board::Valid:
		return true;
	default:
		break;
	}
}

Controller::~Controller() {
	delete board;
	delete playerManager;
}