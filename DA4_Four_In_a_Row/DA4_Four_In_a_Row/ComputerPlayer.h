#pragma once
#include "Player.h"
namespace Core {
	/*
	Simulates a real player using artificial intelligence.
	*/
	class ComputerPlayer : public Player {
	public:
		ComputerPlayer(PlayerManager* manager, std::string name) : Player(manager, name) { }

	private:
		int* grid;

		int calculateBestMove();
	};
}

