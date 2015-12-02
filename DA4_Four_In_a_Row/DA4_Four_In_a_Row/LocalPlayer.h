#pragma once

#include "Player.h"

	/*
	Sending and receiving moves from local input source.
	*/
	class LocalPlayer : public Player {
	public:
		LocalPlayer(PlayerManager* manager, std::string name) : Player(manager, name) { 
		}

		virtual void recieve(int position) override;
	private:
		/*
		Read the computers mouse state.
		*/
		void readMouse();

	};
