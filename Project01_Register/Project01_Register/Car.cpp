#include <iostream>
#include "Car.h"


Car::Car( char* name, int weight ) : Vehicle( name, weight, 4 ) {
}


Car::~Car() {
	std::cout << "Car [Sub class] destroyed for " << Vehicle::name << std::endl;
}
