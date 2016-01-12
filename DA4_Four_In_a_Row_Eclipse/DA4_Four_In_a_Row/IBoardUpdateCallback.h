#pragma once

/*Interface callback for board update*/
class IBoardUpdateCallback {
public:
	/*
	When the game updates. It uses this callback.
	*/
	virtual void onBoardUpdate() = 0;

};
