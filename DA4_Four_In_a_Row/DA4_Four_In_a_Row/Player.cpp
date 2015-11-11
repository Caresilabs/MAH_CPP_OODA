#include "Player.h"

using namespace Core;

Player::Player(PlayerManager* manager, std::string name) : manager(manager), name(name) {
}

bool Player::send(int position) {
	return manager->sendInput(this, position);
}