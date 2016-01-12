#include "PlayerManager.h"
#include "Player.h"
#include "LocalPlayer.h"
#include "ComputerPlayer.h"
#include "RemotePlayer.h"
#include <iostream>


PlayerManager::PlayerManager(Controller* controller, BoardPanel* panel  ,const Settings& settings) : controller(controller) {
	switch (settings.gameType)
	{
	case Settings::GameType::PlayerVSPlayer:
		playerA = new LocalPlayer( this, panel,settings.playerNameA );
		playerB = new LocalPlayer( this, panel,settings.playerNameB );
		break;
	case Settings::GameType::PlayerVSComputer:
		playerA = new LocalPlayer( this, panel,settings.playerNameA );
		playerB = new ComputerPlayer(this, settings.playerNameB, controller->getBoard());
		break;
	case Settings::GameType::PlayerVSRemote:
		playerA = new LocalPlayer( this, panel,settings.playerNameA );
		playerB = new RemotePlayer(this, settings.playerNameB);
		break;
	default:
		playerA = new LocalPlayer( this, panel,settings.playerNameA );
		playerB = new LocalPlayer( this, panel, settings.playerNameB );
		break;
	}

	currentTurn = settings.whoStarts == 1 ? playerA : playerB;
}

void PlayerManager::start() {
	std::cout << currentTurn->getName() << ": ";
	currentTurn->notify( -1 );
}

bool PlayerManager::sendInput(Player* player, int position)
{
	bool valid = controller->makeMove(player == playerA ? 1 : 2, position);

	// If we're not playing anymore, return true and dont switch players
	if (controller->getState() != Controller::State::Playing) {
		return true;
	}

	if (valid) {
		switchPlayer();
		notifyOther(position);
		return true;
	}

	return false;
}


void PlayerManager::switchPlayer(){
	currentTurn = currentTurn == playerA ? playerB : playerA;
	std::cout << currentTurn->getName() << ": ";
}

void PlayerManager::notifyOther(int position){
	currentTurn->notify( position );
}

PlayerManager::~PlayerManager() {
	delete playerA;
	delete playerB;
}
