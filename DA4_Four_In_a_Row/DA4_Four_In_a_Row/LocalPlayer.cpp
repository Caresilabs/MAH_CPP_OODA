#include "LocalPlayer.h"
#include <iostream>

using namespace Core;

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