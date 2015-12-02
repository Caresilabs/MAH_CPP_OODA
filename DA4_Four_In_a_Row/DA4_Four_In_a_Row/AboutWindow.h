#pragma once

#include <string>

	/*
	Displays an about window showing the creator and version.
	*/
	class AboutWindow {
	public:
		AboutWindow() = default;

		/*
		Show window.
		*/
		void show();
	private:

		/*
		Closes the current window. If it's in show state.
		*/
		void close();

		std::string version;
		std::string creator;
		std::string dateOfCreation;
	};
