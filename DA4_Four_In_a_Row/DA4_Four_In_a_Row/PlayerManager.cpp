#include "PlayerManager.h"
#include "Player.h"
#include "LocalPlayer.h"

using namespace Core;

PlayerManager::PlayerManager(Controller* controller, const Settings& settings) : controller(controller) {
	playerA = new LocalPlayer(this, settings.playerNameA);
	playerB = new LocalPlayer(this, settings.playerNameB);

	currentTurn = settings.whoStarts == 1 ? playerA : playerB;
}

void PlayerManager::start() {
	currentTurn->recieve(-1);
}

bool PlayerManager::sendInput(Player* player, int position)
{
	bool valid = controller->makeMove(player == playerA ? 1 : 2, position);

	if (valid) {
		switchPlayer();
		notifyOther(position);
	}

	return valid;
}


void PlayerManager::switchPlayer(){
	currentTurn = currentTurn == playerA ? playerB : playerA;
}

void PlayerManager::notifyOther(int position){
	currentTurn->recieve(position);
}
