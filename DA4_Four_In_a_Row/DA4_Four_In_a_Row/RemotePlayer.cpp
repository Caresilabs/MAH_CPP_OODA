#include "RemotePlayer.h"
#include "NetworkException.h"
#include <iostream>


void RemotePlayer::sendToConnection(int position) {
	try
	{
		throw NetworkException();
	}
	catch (NetworkException e) {
		std::cout << e.error;
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