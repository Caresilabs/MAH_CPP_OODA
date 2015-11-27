#include "LocalPlayer.h"
#include <iostream>



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