#pragma once
#include <string>

#include "PlayerManager.h"

	/*
	An abstract class for recieving and sending moves to the game.
	*/
	class Player {
	public:
		Player(PlayerManager* manager, std::string name);

		/* Disable copy constructor and assignment operator*/
		Player(const Player& rhs) = delete;
		Player& operator=(const Player& rhs) = delete;

		/*
		notify that the other player moved.
		@param the x position on the board
		*/
		virtual void notify(int position) = 0;

		/*
		@return get the player's name
		*/
		std::string getName() const;

	protected:
		PlayerManager* manager;
		std::string name;
	};

