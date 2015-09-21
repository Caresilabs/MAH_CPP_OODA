#include <iostream>
#include "MotorCycle.h"

MotorCycle::MotorCycle( const std::string&name, int weight ) : Vehicle( name, weight, 2 ) {
}


MotorCycle::~MotorCycle() {
	std::cout << "MotorCycle [Sub class] destroyed for " << Vehicle::name << std::endl;
}
