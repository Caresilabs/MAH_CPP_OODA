#pragma once

#include <string>
#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car(const std::string&name, int weight);

	virtual ~Car();
};

