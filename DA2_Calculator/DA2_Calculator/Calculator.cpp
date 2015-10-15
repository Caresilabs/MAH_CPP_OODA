#include "Calculator.h"

IntegerNumber Calculator::add( IntegerNumber integerA, IntegerNumber integerB ) {
	IntegerNumber result;
	result.setInteger( integerA.getInteger() + integerB.getInteger() );
	return result;
}

IntegerNumber Calculator::subtract( IntegerNumber integerA, IntegerNumber integerB ) {
	IntegerNumber result;
	result.setInteger( integerA.getInteger() - integerB.getInteger() );
	return result;
}

IntegerNumber Calculator::multiply( IntegerNumber integerA, IntegerNumber integerB ) {
	IntegerNumber result;
	result.setInteger( integerA.getInteger() * integerB.getInteger() );
	return result;
}

IntegerNumber Calculator::divide( IntegerNumber integerA, IntegerNumber integerB ) {
	IntegerNumber result;
	result.setInteger( integerA.getInteger() / integerB.getInteger() );
	return result;
}
