#pragma once

#include "Vehicle.h"

class MotorCycle : public Vehicle {
public:
	MotorCycle( char* name, int weight );

	virtual ~MotorCycle();
};

