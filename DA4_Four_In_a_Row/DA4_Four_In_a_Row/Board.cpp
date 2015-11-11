#include "Board.h"

using namespace Core;

Board::Board(int width, int height) {
	this->width = width;
	this->height = height;

	grid = new int*[width];
	for (int i = 0; i < width; i++)
	{
		grid[i] = new int[height] {};
	}
}

Board::State Board::insert(int playerId, int x){
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

	if (checkWin()) {
		return Win;
	}

	if (checkFull()) {
		return Full;
	}

	grid[x][y] = playerId;

	return Valid;
}

bool Board::checkWin() {
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