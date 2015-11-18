#include "RemotePlayer.h"

using namespace Core;

void RemotePlayer::sendToConnection(int position) {

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