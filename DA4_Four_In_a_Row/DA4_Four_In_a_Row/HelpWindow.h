#pragma once

#include <string>

namespace GUI {

	/*
	Displays a local html-page describing the game rules.
	*/
	class HelpWindow {
	public:
		HelpWindow() = default;
		void show();
	private:
		void showHTML();
		const static std::string path;
	};
}

