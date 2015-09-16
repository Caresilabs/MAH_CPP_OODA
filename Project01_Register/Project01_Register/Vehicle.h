#pragma once
#include <string>

class Vehicle {
public:
	Vehicle( const std::string& name, int weight, int numWheels );

	void printInformation();
private:
	std::string		name;
	int				weight;
	int				numWheels;
};

