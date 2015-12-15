#pragma once
#include "Player.h"
#include "NetworkException.h"

/*
Sending and recieving input from a remote input source.
*/
class RemotePlayer : public Player {
public:
	RemotePlayer(PlayerManager* manager, std::string name);

	/* Disable copy constructor and assignment operator*/
	RemotePlayer(const RemotePlayer& rhs) = delete;
	RemotePlayer& operator=(const RemotePlayer& rhs) = delete;

	virtual void notify( int position ) override;
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

