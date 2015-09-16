#include <iostream>
#include "Vehicle.h"


Vehicle::Vehicle( const std::string& name, int weight, int numWheels )
	: name(name), weight(weight), numWheels(numWheels) {}

void Vehicle::printInformation() {
	std::cout << "{ " << std::endl;
	std::cout << "\tName: " << name;
	std::cout << "\tWeight: " << weight;
	std::cout << "\tNumber of wheels: " << numWheels;
	std::cout << std::endl << "}" << std::endl;
}


