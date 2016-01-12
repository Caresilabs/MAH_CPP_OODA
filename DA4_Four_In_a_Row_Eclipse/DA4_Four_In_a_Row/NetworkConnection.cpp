#include "NetworkConnection.h"
#include "RemotePlayer.h"
#include <iostream>

NetworkConnection::NetworkConnection( RemotePlayer* player, bool isHost ) : player(player), isHost(isHost) {

}

void NetworkConnection::sendToConnection( int position ) {
	try {
		throw new NetworkException();
	}
	catch ( NetworkException* e ) {
		std::cout << e->error;
		delete e;
	}
}

void NetworkConnection::recieveFromConnection( int position ) {
	player->recieveFromConnection(position);
}
