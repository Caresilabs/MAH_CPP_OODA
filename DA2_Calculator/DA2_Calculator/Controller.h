#pragma once

#include "IntegerNumber.h"
#include "Calculator.h"
#include "UserInterface.h"


class Controller {
public:
	Controller() = default;

	void mainLoop();


private:
	IntegerNumber integerA;
	IntegerNumber integerB;
	IntegerNumber integerAnswer;

	Calculator aCalcultor;
	UserInterface aUserInterface;

	void calculate(char operation);
};

