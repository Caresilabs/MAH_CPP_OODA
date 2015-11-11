#pragma once

#include "Settings.h"
#include "Controller.h"

namespace Core {
	class Player;

	/*
	Manages input from the players and whose turn it is.
	*/
	class PlayerManager {
	public:
		PlayerManager(Controller* controller, const Settings& settings);

		void start();

		/*
		Tries to insert a piece using the controller.
		@param the player.
		@param the x position on the board
		@return if the move was valid
		*/
		bool sendInput(Player* player, int position);

	private:
		Controller* controller;

		Player* playerA;
		Player* playerB;

		Player* currentTurn;

		void switchPlayer();
		void notifyOther(int position);

	};
}

