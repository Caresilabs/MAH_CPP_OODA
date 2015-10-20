#pragma once

#include "Settings.h"
#include "Controller.h"

class Player;

class PlayerManager {
public:
	PlayerManager(Controller* controller, const Settings& settings);

	bool sendInput(Player* player, int position);

private:
	Controller* controller;

	Player* playerA;
	Player* playerB;

	Player* currentTurn;

	void switchPlayer();
	void notifyOther( int position );
	
};

