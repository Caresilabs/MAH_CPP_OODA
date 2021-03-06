#pragma once

#include "Player.h"

namespace Core {
	/*
	Sending and receiving moves from local input source.
	*/
	class LocalPlayer : public Player {
	public:
		LocalPlayer(PlayerManager* manager, std::string name) : Player(manager, name) { }
	private:
		void readMouse();

	};
}
