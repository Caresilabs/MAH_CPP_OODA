#pragma once

namespace Core {
	/*
	Board is responsible for setting a piece in a valid position, and also checks if the board is full or a player has won.
	*/
	class Board {
	public:
		Board(int width, int height);

		/*
		Inserts a piece on the board.
		@param player id who want to insert.
		@param the x position on the board
		@return if the move was valid
		*/
		bool insert(int playerId, int x);

		~Board();
	private:
		int* grid;

		void checkWin();
		void checkFull();
	};
}

