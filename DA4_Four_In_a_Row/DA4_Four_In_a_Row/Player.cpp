#include "Player.h"



Player::Player(PlayerManager* manager, std::string name) : manager(manager), name(name) {
}

bool Player::send(int position) {
	return manager->sendInput(this, position);
}