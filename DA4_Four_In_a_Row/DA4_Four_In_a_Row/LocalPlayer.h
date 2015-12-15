#pragma once

#include "Player.h"

	/*
	Sending and receiving moves from local input source.
	*/
	class LocalPlayer : public Player {
	public:
		LocalPlayer(PlayerManager* manager, std::string name);

		/* Disable copy constructor and assignment operator*/
		LocalPlayer(const LocalPlayer& rhs) = delete;
		LocalPlayer& operator=(const LocalPlayer& rhs) = delete;

		virtual void notify( int position ) override;
	private:
		/*
		Read the computers mouse state.
		*/
		void readMouse();

	};
