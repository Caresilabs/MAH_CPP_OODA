#include "Controller.h"

void Controller::mainLoop() {
	do {
		integerA.setInteger(aUserInterface.getIntegerA());
		integerB.setInteger(aUserInterface.getIntegerB());

		char operation = aUserInterface.getOperation();
		calculate(operation);

		aUserInterface.setAnswer(integerAnswer.getInteger());

	} while ( aUserInterface.getOneMoreTime() == 'y');
}

void Controller::calculate( char operation ) {
	switch ( operation ) {
	case '+':
		integerAnswer = aCalcultor.add(integerA, integerB);
		break;
	case '-':
		integerAnswer = aCalcultor.subtract( integerA, integerB );
		break;
	case '*':
		integerAnswer = aCalcultor.multiply( integerA, integerB );
		break;
	case '/':
		integerAnswer = aCalcultor.divide( integerA, integerB );
		break;
	default:
		integerAnswer.setInteger(0);
		break;
	}
}

