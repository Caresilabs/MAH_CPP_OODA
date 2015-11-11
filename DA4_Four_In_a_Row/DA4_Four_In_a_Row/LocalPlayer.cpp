#include "LocalPlayer.h"
#include <iostream>

using namespace Core;

void LocalPlayer::readMouse() {
	int pos;
	std::cin >> pos;
	send(pos);
}



void LocalPlayer::recieve(int position)  {
	readMouse();
}