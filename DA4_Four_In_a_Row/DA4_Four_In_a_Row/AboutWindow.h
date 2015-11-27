#pragma once

#include <string>

	/*
	Displays an about window showing the creator and version.
	*/
	class AboutWindow {
	public:
		AboutWindow() = default;
		void show();
	private:
		void close();

		std::string version;
		std::string creator;
		std::string dateOfCreation;
	};
