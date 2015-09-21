#pragma once

#include <string>
#include <iostream>

class Vehicle {
public:
	Vehicle( char* name, int weight, int numWheels );

	void				printInformation();

	virtual				~Vehicle();

protected:
	char*			name;
	int				weight;
	int				numWheels;
};

