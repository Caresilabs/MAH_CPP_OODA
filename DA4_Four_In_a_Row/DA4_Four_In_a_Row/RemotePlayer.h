#pragma once
#include "Player.h"

namespace Core {
	/*
	Sending and recieving input from a remote input source.
	*/
	class RemotePlayer : public Player {
	public:
		RemotePlayer(PlayerManager* manager, std::string name) : Player(manager, name) { }

		virtual void recieve(int position) override;
	private:

		char* serverConnection;
		char* clientConnection;

		void sendToConnection(int position);
		void recieveFromConnection(int position);
	};
}

