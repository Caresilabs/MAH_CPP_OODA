#pragma once

#include <string>
#include <iostream>

class UserInterface {
public:
	UserInterface() = default;
	
	int getIntegerA();

	int getIntegerB();

	char getOperation();

	void setAnswer( int result );

	char getOneMoreTime();

private:
	std::string readLine();

	int readInt();
};

