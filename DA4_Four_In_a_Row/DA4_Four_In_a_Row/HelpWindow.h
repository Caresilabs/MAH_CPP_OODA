#pragma once

#include <string>


	/*
	Displays a local html-page describing the game rules.
	*/
	class HelpWindow {
	public:
		HelpWindow() = default;

		/*
		Show window.
		*/
		void show();
	private:
		/*
		Show an embeded Browser with a custom html page.
		*/
		void showHTML();

		const static std::string path;
	};

