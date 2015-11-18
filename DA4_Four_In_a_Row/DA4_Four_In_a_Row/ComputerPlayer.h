#pragma once
#include "Player.h"
namespace Core {
	/*
	Simulates a real player using artificial intelligence.
	*/
	class ComputerPlayer : public Player {
	public:
		ComputerPlayer(PlayerManager* manager, std::string name, int boardWidth, int boardHeight);

		virtual void recieve(int position) override;

		~ComputerPlayer();

	private:
		int** grid;
		int boardWidth;
		int boardHeight;

		int calculateBestMove();
		void doAI();
	};
}

