#pragma once
#include <string>

#include "PlayerManager.h"

namespace Core {
	/*
	An abstract class for recieving and sending moves to the game.
	*/
	class Player {
	public:
		Player(PlayerManager* manager, std::string name);

		/* Deletes the copy constructor */
		Player(const Player& rhs) = delete;

		/* Deletes the assignment operator */
		Player& operator=(const Player& rhs) = delete;

		/*
		Tries to insert a piece on the board.
		@param the x position on the board
		@return if the move was valid
		*/
		virtual bool send(int position) = 0;

		/*
		Get's the other players move.
		@param the x position on the board
		*/
		virtual void revieve(int position) = 0;

	private:
		PlayerManager* manager;
		std::string name;
	};
}

