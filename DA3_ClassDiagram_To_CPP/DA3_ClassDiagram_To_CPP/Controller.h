#pragma once

#include "Board.h"
#include "Settings.h"

namespace Core {
	class PlayerManager;

	/*
	The Controller class is the key class of the "four in a row" application. It creates the different objects needed to play the game. The Controllers main tasks are to set up a game and to control the game play.
	The controller interacts with a MainWindow object to receive commands made by the user, such as exit, restart, quit and start new game.
	*/
	class Controller {
	public:
		Controller(Settings settings);

		void startGame();
		void restartGame();
		void exitGame();

		/*
		Inserts a piece on the board.
		@param player id who want to insert.
		@param the x position on the board
		@return if the move was valid
		*/
		bool makeMove(int player, int x);

		const Board* getBoard() const;

	private:
		Board* board;
		PlayerManager* playerManager;
	};
}

