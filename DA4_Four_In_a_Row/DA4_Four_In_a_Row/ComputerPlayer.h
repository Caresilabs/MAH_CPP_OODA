#pragma once
#include "Player.h"
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

		/*
		Calculate the best move for the AI
		@return position of the best move.
		*/
		int calculateBestMove();

		/*
		Run the AI simulation.
		*/
		void doAI();
	};

