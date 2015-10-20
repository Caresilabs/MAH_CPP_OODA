#pragma once

#include <string>

class HelpWindow {
public:
	HelpWindow() = default;
private:
	void showHTML();
	const static std::string path;
};

