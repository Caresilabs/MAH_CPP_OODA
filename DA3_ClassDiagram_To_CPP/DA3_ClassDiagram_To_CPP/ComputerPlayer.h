#pragma once
#include "Player.h"
class ComputerPlayer : public Player {
public:
	ComputerPlayer( PlayerManager* manager, std::string name ) : Player( manager, name ) { }

private:
	int* grid;

	int calculateBestMove();
};

