#include "ComputerPlayer.h"
#include <cstdlib>
#include <ctime>

ComputerPlayer::ComputerPlayer( PlayerManager* manager, std::string name, const Board* board ) : Player( manager, name ), board( board ) {
}

int ComputerPlayer::calculateBestMove() {
	srand(time(0));

	return rand() % board->getWidth();
}

void ComputerPlayer::doAI() {
	int bestMove = calculateBestMove();
	if (!send(bestMove)) {
		doAI();
	}
}

void ComputerPlayer::notify( int position ) {
	doAI();
}

