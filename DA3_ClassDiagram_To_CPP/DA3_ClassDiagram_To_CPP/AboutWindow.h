#pragma once

#include <string>

class AboutWindow {
public:
	AboutWindow() = default;
private:
	void close();

	std::string version;
	std::string creator;
	std::string dateOfCreation;
};

