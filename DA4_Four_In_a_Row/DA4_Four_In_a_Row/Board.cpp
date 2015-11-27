#include "Board.h"



Board::Board(int width, int height, int rowsToWin) : width(width), height(height),rowsToWin(rowsToWin) {
	grid = new int*[width];
	for (int i = 0; i < width; i++)
	{
		grid[i] = new int[height] {};
	}
}

Board::State Board::insert(int playerId, int x){
	if (x >= width)
		return State::Invalid;

	int y = 0;
	for (; y < height; y++)
	{
		if (grid[x][y] != 0) {
			break;
		}
	}
	--y;

	if (y < 0) {
		return Invalid;
	}

	if (checkFull()) {
		return Full;
	}

	grid[x][y] = playerId;

	if (checkWin(playerId, x, y)) {
		return Win;
	}

	return Valid;
}

int Board::findCount(int player, int x, int y, int dirX, int dirY) {
		
	int count = 0;

	while (true) {
		if (x < 0) break;
		if (x >= width) break;
		if (y < 0) break;
		if (y >= height) break;
		if (grid[x][y] == player) {
			x += dirX;
			y += dirY;
			++count;
		}
		else {
			return count;
		}
	}

	return count;

}

bool Board::checkWin(int player, int x, int y) {
	if (findCount(player, x, y, -1, 0) + findCount(player, x, y, 1, 0) -1 >= rowsToWin) return true;
	if (findCount(player, x, y, 0, -1) + findCount(player, x, y, 0, 1) -1 >= rowsToWin) return true;
	if (findCount(player, x, y, -1, -1) + findCount(player, x, y, 1, 1) -1 >= rowsToWin) return true;
	if (findCount(player, x, y, -1, 1) + findCount(player, x, y, 1, -1) -1 >= rowsToWin) return true;

	return false;
}

bool Board::checkFull(){
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (grid[x][y] == 0)
				return false;
		}
	}
	return true;
}

Board::~Board() {
	for (int i = 0; i < width; i++)
	{
		delete grid[i];
	}
	delete grid;
}