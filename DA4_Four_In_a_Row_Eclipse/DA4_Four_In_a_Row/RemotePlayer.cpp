#include "RemotePlayer.h"


RemotePlayer::RemotePlayer(PlayerManager* manager, std::string name) : Player(manager, name), connection(new NetworkConnection(this, true)) {
}

void RemotePlayer::sendToConnection(int position) {
	connection->sendToConnection( position );
}

void RemotePlayer::recieveFromConnection(int position){
	manager->sendInput(this, position);
}

void RemotePlayer::notify( int position ) {
	// mock
	if (manager->sendInput(this, 1)) {
		sendToConnection(1);
	}
}

RemotePlayer::~RemotePlayer() {
	delete connection;
}