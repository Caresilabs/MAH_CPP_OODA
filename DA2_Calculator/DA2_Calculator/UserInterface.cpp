#include "UserInterface.h"

int UserInterface::getIntegerA() {
	std::cout << "integer A:" << std::endl;
	return readInt();
}

int UserInterface::getIntegerB() {
	std::cout << "integer B:" << std::endl;
	return readInt();
}

char UserInterface::getOperation() {
	std::cout << "operation:" << std::endl;
	return readLine()[0];
}

void UserInterface::setAnswer( int result ) {
	std::cout << "result:" << std::endl;
	std::cout << result << std::endl;
}

char UserInterface::getOneMoreTime() {
	std::cout << "one more time y/n:" << std::endl;
	return readLine()[0];
}

std::string UserInterface::readLine() {
	std::string result;
	std::cin >> result;
	return result;
}

int UserInterface::readInt() {
	int result;
	std::cin >> result;
	return result;
}
