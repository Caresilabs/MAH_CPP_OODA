#include "Controller.h"
#include "PlayerManager.h"



Controller::Controller(IBoardUpdateCallback* callback) : boardUpdateCallback(callback){
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
	boardUpdateCallback->onBoardUpdate();

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

	if (board == nullptr) {
		int i = 1;
	}
	Board::State state = board->insert(player, x);

	switch (state)
	{
	case Board::Full:
		this->state = State::GameOver;
		break;
	case Board::Invalid:
		break;
	case Board::Win:
		this->state = State::GameOver;
		break;
	case Board::Valid:
		break;
	default:
		break;
	}

	if (state != Board::Invalid) 
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