#include "Controller.h"
#include "PlayerManager.h"

using namespace Core;

Controller::Controller(Core::IBoardUpdateCallback* callback) : boardUpdateCallback(callback){
}

void Controller::setupNewGame(Settings settings) {
	state = Playing;
	board = new Board(settings.gridWidth, settings.gridHeight, settings.rowsToWin);
	playerManager = new PlayerManager(this, settings);
}

void Controller::startGame() {
	playerManager->start();
}

void Controller::restartGame() {
	delete playerManager;
	delete board;

	// TODO
	setupNewGame(Settings());
}

void Controller::exitGame() {
	state = Exit;
	delete playerManager;
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
		this->state = State::GameOver;
		break;
	case Core::Board::Invalid:
		break;
	case Core::Board::Win:
		this->state = State::GameOver;
		break;
	case Core::Board::Valid:
		break;
	default:
		break;
	}

	boardUpdateCallback->onBoardUpdate();

	if (state == Board::Invalid) {
		return false;
	}

	return true;
}

Controller::~Controller() {
	delete board;
	delete playerManager;
}