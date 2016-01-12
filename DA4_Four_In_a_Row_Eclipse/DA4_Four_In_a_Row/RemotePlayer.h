#pragma once

#include "NetworkConnection.h"
#include "Player.h"


/*
Sending and recieving input from a remote input source.
*/
class RemotePlayer : public Player {
public:
	RemotePlayer(PlayerManager* manager, std::string name);

	~RemotePlayer();

	/* Disable copy constructor and assignment operator*/
	RemotePlayer(const RemotePlayer& rhs) = delete;
	RemotePlayer& operator=(const RemotePlayer& rhs) = delete;

	virtual void notify( int position ) override;

	/*
	@param position to recieve
	*/
	void recieveFromConnection( int position );

private:

	/**
 * @directed true
*/
NetworkConnection* connection;

	/*
	@param position to send
	*/
	void sendToConnection(int position);

};

