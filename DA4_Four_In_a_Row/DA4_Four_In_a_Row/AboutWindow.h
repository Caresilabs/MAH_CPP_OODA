#pragma once

#include <string>

namespace GUI {

	/*
	Displays an about window showing the creator and version.
	*/
	class AboutWindow {
	public:
		AboutWindow() = default;
	private:
		void close();

		std::string version;
		std::string creator;
		std::string dateOfCreation;
	};
}
