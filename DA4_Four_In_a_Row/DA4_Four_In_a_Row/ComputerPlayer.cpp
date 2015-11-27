#include "ComputerPlayer.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>



ComputerPlayer::ComputerPlayer(PlayerManager* manager, std::string name, int boardWidth, int boardHeight) : Player(manager, name), boardWidth(boardWidth), boardHeight(boardHeight) { 
	grid = new int*[boardWidth];
	for (int i = 0; i < boardWidth; i++)
	{
		grid[i] = new int[boardHeight];
	}
}

int ComputerPlayer::calculateBestMove() {
	srand(time(0));

	return rand() % boardWidth;
}

void ComputerPlayer::doAI() {
	int bestMove = calculateBestMove();
	if (!send(bestMove)) {
		doAI();
	}
	else {
	//	std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
		int y = 0;
		for (; y < boardHeight; y++)
		{
			if (grid[bestMove][y] != 0) {
				break;
			}
		}
		--y;

		grid[bestMove][y] = 1;
	}
}

void ComputerPlayer::recieve(int position)  {
	if (position < 0 || position >= boardWidth) {
		doAI();
		return;
	}

	int y = 0;
	for (; y < boardHeight; y++)
	{
		if (grid[position][y] != 0) {
			break;
		}
	}
	--y;

	grid[position][y] = 2;

	doAI();
}

ComputerPlayer::~ComputerPlayer() {
	for (int i = 0; i < boardWidth; i++)
	{
		delete grid[i];
	}
	delete grid;
}