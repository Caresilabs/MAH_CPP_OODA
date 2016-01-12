#pragma once

#include <string>

	/*
	Settings is a datacontainer for setting up a game.
	*/
	struct Settings {
	public:
		enum class GameType {
			PlayerVSPlayer,
			PlayerVSComputer,
			PlayerVSRemote
		};

		Settings() = default;

		int gridWidth;
		int gridHeight;

		std::string playerNameA;
		std::string playerNameB;

		GameType gameType;

		int whoStarts;
		int rowsToWin;

		// Network data
		std::string ip;
		short port;
		bool isHost;

	};

