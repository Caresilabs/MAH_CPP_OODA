#pragma once

#include <string>
#include "Vehicle.h"

class MotorCycle : public Vehicle {
public:
	MotorCycle( const std::string&name, int weight );

	virtual ~MotorCycle();
};

