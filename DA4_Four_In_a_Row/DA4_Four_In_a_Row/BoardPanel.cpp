#include "BoardPanel.h"
#include "Board.h"
#include <iostream>

using namespace GUI;

void BoardPanel::draw(const Core::Board* board) {
	system("cls");
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