#pragma once

#include <string>

struct Settings {
public:
	enum class GameType {
		PlayerAVSPlayerB
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

