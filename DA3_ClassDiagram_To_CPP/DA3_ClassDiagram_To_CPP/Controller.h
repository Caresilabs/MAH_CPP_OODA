#pragma once

#include "Board.h"
#include "Settings.h"

class PlayerManager;

class Controller {
public:
	Controller(Settings settings);

	void startGame();
	void restartGame();
	void exitGame();
	bool makeMove( int player, int x );

	const Board* getBoard() const;

private:
	Board* board;
	PlayerManager* playerManager;
};

