#pragma once

#include "Board.h"
#include "Settings.h"
#include "IBoardUpdateCallback.h"

	class PlayerManager;

	/*
	The Controller class is the key class of the "four in a row" application. It creates the different objects needed to play the game. The Controllers main tasks are to set up a game and to control the game play.
	The controller interacts with a MainWindow object to receive commands made by the user, such as exit, restart, quit and start new game.
	*/
	class Controller {
	public:
		enum State {
			GameOver, Playing, Exit
		};

		Controller(IBoardUpdateCallback* callback);

		/*
		Init a new game from settings. Make sure to call startGame() after.
		*/
		void setupNewGame(Settings settings);

		/*
		Start the actual game.
		*/
		void startGame();

		/*
		Restart current session.
		*/
		void restartGame();

		/*
		Exit the current game
		*/
		void exitGame();

		/*
		Inserts a piece on the board.
		@param player id who want to insert.
		@param the x position on the board
		@return if the move was valid
		*/
		bool makeMove(int player, int x);

		const Board* getBoard() const { return board; }
		const State getState() const { return state; }

		~Controller();

	private:
		Board* board;
		PlayerManager* playerManager;
		IBoardUpdateCallback* boardUpdateCallback;
		State state;
	};

