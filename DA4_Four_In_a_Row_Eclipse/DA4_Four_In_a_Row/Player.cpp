#include "Player.h"


Player::Player(PlayerManager* manager, std::string name) : manager(manager), name(name) {
}


std::string Player::getName() const { 
	return name;
};