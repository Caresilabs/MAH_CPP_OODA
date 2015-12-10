#pragma once

#include <string>

	/*
	Displays an about window showing the creator and version.
	*/
	class AboutWindow {
	public:
		AboutWindow() = default;

		/* Disable copy constructor and assignment operator*/
		AboutWindow(const AboutWindow& rhs) = delete;
		AboutWindow& operator=(const AboutWindow& rhs) = delete;

		/*
		Show window.
		*/
		void show();
	private:

		/*
		Closes the current window. If it's in show state.
		*/
		void close();

		/* About data */
		std::string version;
		std::string creator;
		std::string dateOfCreation;
	};
