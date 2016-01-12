#pragma once

#include "NetworkException.h"

class RemotePlayer;

class NetworkConnection {
public:

	NetworkConnection(RemotePlayer* player, bool isHost);
	
	/* Disable copy constructor and assignment operator*/
	NetworkConnection( const NetworkConnection& rhs ) = delete;
	NetworkConnection& operator=( const NetworkConnection& rhs ) = delete;


	/*
	@param position to send
	*/
	void sendToConnection( int position );

	/*
	@param position to recieve
	*/
	void recieveFromConnection( int position );

private:

	/**
 * @directed true
*/
RemotePlayer* player;
	bool isHost;
	int ip;
};

