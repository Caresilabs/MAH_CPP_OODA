#pragma once
#include "Player.h"

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

		/*
		@param position to send
		*/
		void sendToConnection(int position);

		/*
		@param position to recieve
		*/
		void recieveFromConnection(int position);
	};

