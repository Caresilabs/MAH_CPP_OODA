#pragma once

namespace Core {
	class Board;
}

namespace GUI {


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
		void draw(const Core::Board* board);

	};
}

