#pragma once

#include "IntegerNumber.h"

class Calculator {
public:
	Calculator() = default;

	IntegerNumber add(IntegerNumber integerA, IntegerNumber integerB);
	IntegerNumber subtract( IntegerNumber integerA, IntegerNumber integerB );
	IntegerNumber multiply( IntegerNumber integerA, IntegerNumber integerB );
	IntegerNumber divide( IntegerNumber integerA, IntegerNumber integerB );
};

