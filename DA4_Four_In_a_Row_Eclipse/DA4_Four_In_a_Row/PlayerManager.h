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
	/**
 * @directed true
*/
/**
 * @directed true
*/
Controller* controller;

	/**
 * @clientRole Player A
 * @directed true
*/
Player* playerA;
	/**
 * @clientRole Player B 
 * @directed true
*/
Player* playerB;

	

/**
 * @label Manages
 * @supplierRole Manager
 * @clientRole Current Player
 * @directed true
*/
/**
 * @clientRole CurrentPlayer
 * @label Manages
*/
/**
 * @directed true
 * @label Manages
 * @supplierRole Manager
 * @clientRole CurrentPlayer
*/
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

