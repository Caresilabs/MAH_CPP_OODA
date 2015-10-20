#pragma once
class Board {
public:
	Board();

	bool insert( int playerId, int x );

	~Board();
private:
	int* grid;

	void checkWin();
	void checkFull();
};

