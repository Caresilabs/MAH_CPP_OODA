#pragma once
#include <string>

#include "PlayerManager.h"

class Player {
public:
	Player(PlayerManager* manager, std::string name);

	virtual void send( int position ) = 0;
	virtual void revieve( int position ) = 0;

private:
	PlayerManager* manager;
	std::string name;
};

