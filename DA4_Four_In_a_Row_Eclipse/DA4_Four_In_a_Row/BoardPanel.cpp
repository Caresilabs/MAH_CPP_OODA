#include "BoardPanel.h"
#include "Board.h"
#include <iostream>

void BoardPanel::draw(const Board* board) {
	system("cls");
	std::cout << "Enter -1 to exit." << "\n";

	for (int i = 0; i < board->getWidth(); i++)
	{
		std::cout << i << " ";
	}
	std::cout << "\n\n";

	for (int y = 0; y < board->getHeight(); y++)
	{
		for (int x = 0; x < board->getWidth(); x++)
		{
			std::cout << board->getGrid()[x][y] << " ";
		}
		std::cout << "\n";
	}
}

int BoardPanel::readMouse() {
	int pos;
	std::cin >> pos;
	return pos;
}