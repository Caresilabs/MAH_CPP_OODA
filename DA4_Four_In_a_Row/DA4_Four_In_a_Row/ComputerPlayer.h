#pragma once
#include "Player.h"

/*
Simulates a real player using artificial intelligence.
*/
class ComputerPlayer : public Player {
public:
	ComputerPlayer(PlayerManager* manager, std::string name, int boardWidth, int boardHeight);

	/* Disable copy constructor and assignment operator*/
	ComputerPlayer(const ComputerPlayer& rhs) = delete;
	ComputerPlayer& operator=(const ComputerPlayer& rhs) = delete;

	/* Get the opposite player's move.
	@param position the x position that is recieved.
	*/
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
	add the my piece to position x. Y is calculated
	@param x x position to add
	*/
	void ComputerPlayer::addPieceToAIGrid(int x);

	/*
	Run the AI simulation.
	*/
	void doAI();
};

