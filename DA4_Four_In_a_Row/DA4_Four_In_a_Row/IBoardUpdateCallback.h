#pragma once

	class IBoardUpdateCallback {
	public:
		/*
		When the game updates. It uses this callback.
		*/
		virtual void onBoardUpdate() = 0;
	};
