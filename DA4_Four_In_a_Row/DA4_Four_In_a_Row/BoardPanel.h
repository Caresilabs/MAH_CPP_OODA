#pragma once

class Board;

/*
Draws the board.
*/
class BoardPanel {
public:
	BoardPanel() = default;

	/* Disable copy constructor and assignment operator*/
	BoardPanel(const BoardPanel& rhs) = delete;
	BoardPanel& operator=(const BoardPanel& rhs) = delete;

	/*
	Draws the board.
	@param the board to draw
	*/
	void draw(const Board* board);

};

