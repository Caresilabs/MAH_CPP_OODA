#include "LocalPlayer.h"
#include <iostream>

LocalPlayer::LocalPlayer(PlayerManager* manager, BoardPanel* panel ,std::string name) : Player(manager, name), panel(panel) {
}

void LocalPlayer::readMouse() {
	int pos = panel->readMouse();

	if (!manager->sendInput(this, pos)) {
		readMouse();
	}
}

void LocalPlayer::notify(int position)  {
	readMouse();
}