#include "Player.h"



Player::Player(PlayerManager* manager, std::string name) : manager(manager), name(name) {
}

bool Player::send(int position) {
	return manager->sendInput(this, position);
}

std::string Player::getName() const { 
	return name;
};