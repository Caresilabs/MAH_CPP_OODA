#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car( char* name, int weight);

	virtual ~Car();
};

