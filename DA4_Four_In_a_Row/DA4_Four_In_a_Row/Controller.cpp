#include "Controller.h"
#include "PlayerManager.h"
#include "Board.h"

Controller::Controller( IBoardUpdateCallback* callback ) : boardUpdateCallback( callback ) {
}

void Controller::setupNewGame( Settings settings ) {
	state = Playing;
	board = new Board( settings.gridWidth, settings.gridHeight, settings.rowsToWin );
	playerManager = new PlayerManager( this, settings );
}

void Controller::startGame() {
	playerManager->start();
}

void Controller::restartGame() {
	delete playerManager;
	delete board;

	boardUpdateCallback->onBoardUpdate();

	setupNewGame( Settings() );
}

void Controller::exitGame() {
	//state = Exit;

	delete playerManager;
	delete board;
}

bool Controller::makeMove( int player, int x ) {

	// Exit
	if ( x == -1 ) {
		this->state = State::Exit;
		return true;
	}

	Board::State state = board->insert( player, x );

	switch ( state ) {
	case Board::Full:
		this->state = State::GameOver;
		break;

	case Board::Invalid:
		return false;

	case Board::Win:
		this->state = State::GameOver;
		break;

	case Board::Valid:
		boardUpdateCallback->onBoardUpdate();
		break;

	default:
		break;
	}

	return true;
}

const Board* Controller::getBoard() const {
	return board;
}

const Controller::State Controller::getState() const {
	return state;
}

Controller::~Controller() {
	delete board;
	delete playerManager;
}