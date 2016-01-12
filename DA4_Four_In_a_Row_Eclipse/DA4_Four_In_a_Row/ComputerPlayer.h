#pragma once
#include "Player.h"
#include "Board.h"

/*
Simulates a real player using artificial intelligence.
*/
class ComputerPlayer : public Player {
public:
	ComputerPlayer(PlayerManager* manager, std::string name, const Board* board);

	/* Disable copy constructor and assignment operator*/
	ComputerPlayer(const ComputerPlayer& rhs) = delete;
	ComputerPlayer& operator=(const ComputerPlayer& rhs) = delete;

	/* Get the opposite player's move.
	@param position the x position that is recieved.
	*/
	virtual void notify( int position ) override;

private:

	/* The board to lookup 
 * @directed true
*/
const Board* board;

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

