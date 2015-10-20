#pragma once

#include "Player.h"

class LocalPlayer : public Player {
public:
	LocalPlayer( PlayerManager* manager, std::string name ) : Player(manager, name) { }
private:
	void readMouse();

};

