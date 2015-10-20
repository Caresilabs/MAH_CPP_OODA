#pragma once
#include "Player.h"

class RemotePlayer : public Player {
public:
	RemotePlayer( PlayerManager* manager, std::string name ) : Player( manager, name ) { }
private:

	char* serverConnection;
	char* clientConnection;

	void sendToConnection( int position );
	void revieveFromConnection( int position );
};

