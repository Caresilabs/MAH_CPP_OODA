#include "RemotePlayer.h"
#include <iostream>

RemotePlayer::RemotePlayer(PlayerManager* manager, std::string name) : Player(manager, name) {
}

void RemotePlayer::sendToConnection(int position) {
	try
	{
		throw new NetworkException();
	}
	catch (NetworkException* e) {
		std::cout << e->error;
		delete e;
	}
}

void RemotePlayer::recieveFromConnection(int position){
	send(position);
}

void RemotePlayer::recieve(int position) {
	// mock
	if (send(1)) {
		sendToConnection(1);
	}
}