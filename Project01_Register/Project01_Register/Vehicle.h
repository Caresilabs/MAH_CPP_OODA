#pragma once

#include <string>
#include <iostream>

class Vehicle {
public:
	Vehicle( const std::string& name, int weight, int numWheels );

	void				printInformation();

	virtual				~Vehicle();

protected:
	std::string		name;
	int				weight;
	int				numWheels;
};

