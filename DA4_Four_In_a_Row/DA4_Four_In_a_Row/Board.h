#pragma once

	/*
	Board is responsible for setting a piece in a valid position, and also checks if the board is full or a player has won.
	*/
	class Board {
	public:

		enum State {
			Full, Invalid, Win, Valid
		};

		Board(int width, int height, int rowsToWin);

		/* Disable copy constructor and assignment operator*/
		Board(const Board& rhs) = delete;
		Board& operator=(const Board& rhs) = delete;

		/*
		Inserts a piece on the board.
		@param player id who want to insert.
		@param the x position on the board
		@return if the move was valid
		*/
		State insert(int playerId, int x);

		int getWidth() const;

		int getHeight() const;

		int** getGrid() const;

		~Board();
	private:
		int** grid;
		
		int width;
		int height;
		int rowsToWin;

		/* 
		Check if the board has a winner
		@param player the player id
		@param x the x position that was recently placed
		@param y the y position that was recently placed
		@return if someone has won
		*/
		bool checkWin(int player, int x, int y);

		/*
		@param player the player id
		@param x the start postion on x axis
		@param y the start postion on y axis
		@param dirX the x-direction multiplier
		@param dirY the y-direction multiplier
		@return the total pieces in one direction by the @player
		*/
		int findCount(int player, int x, int y, int dirX, int dirY);

		/*
		@return if the board is full
		*/
		bool checkFull();
	};

