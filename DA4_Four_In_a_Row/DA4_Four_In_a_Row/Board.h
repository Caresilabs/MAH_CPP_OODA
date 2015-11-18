#pragma once

namespace Core {
	/*
	Board is responsible for setting a piece in a valid position, and also checks if the board is full or a player has won.
	*/
	class Board {
	public:

		enum State {
			Full, Invalid, Win, Valid
		};

		Board(int width, int height, int rowsToWin);

		/*
		Inserts a piece on the board.
		@param player id who want to insert.
		@param the x position on the board
		@return if the move was valid
		*/
		State insert(int playerId, int x);

		int getWidth() const { return width; }
		int getHeight() const { return height; }

		int** getGrid() const { return grid; }

		~Board();
	private:
		int** grid;
		
		int width;
		int height;
		int rowsToWin;

		bool checkWin(int player, int x, int y);
		int findCount(int player, int x, int y, int dirX, int dirY);

		bool checkFull();
	};
}

