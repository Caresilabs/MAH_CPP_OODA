#pragma once

#include "Settings.h"
#include "Controller.h"

class Player;
class BoardPanel;

/*
Manages input from the players and whose turn it is.
*/
class PlayerManager {
public:
	PlayerManager( Controller* controller, BoardPanel* panel, const Settings& settings );

	/* Disable copy constructor and assignment operator*/
	PlayerManager( const PlayerManager& rhs ) = delete;
	PlayerManager& operator=( const PlayerManager& rhs ) = delete;

	/*
	Start the playermanager
	*/
	void start();

	/*
	Tries to insert a piece using the controller.
	@param the player.
	@param the x position on the board
	@return if the move was valid
	*/
	bool sendInput( Player* player, int position );

	~PlayerManager();

private:
	Controller* controller;

	Player* playerA;
	Player* playerB;

	Player* currentTurn;

	/*
	Switch the current player
	*/
	void switchPlayer();

	/*
	@param position the position to notify the other user
	*/
	void notifyOther( int position );

};

