#pragma once

	class Board;


	/*
	Draws the board.
	*/
	class BoardPanel {
	public:
		BoardPanel() = default;

		/*
		Draws the board.
		@param the board to draw
		*/
		void draw(const Board* board);

	};

