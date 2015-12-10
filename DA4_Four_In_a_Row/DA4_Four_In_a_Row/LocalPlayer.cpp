#include "LocalPlayer.h"
#include <iostream>

LocalPlayer::LocalPlayer(PlayerManager* manager, std::string name) : Player(manager, name) {
}

void LocalPlayer::readMouse() {
	int pos;
	std::cin >> pos;
	if (!send(pos)) {
		readMouse();
	}
}

void LocalPlayer::recieve(int position)  {
	readMouse();
}