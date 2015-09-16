#include <iostream>
#include "Registry.h"
#include "Vehicle.h"
#include "Car.h"
#include "MotorCycle.h"

void test() {
	// Test class

	Registry<int, Vehicle> registry( 3 );
	registry.put( 22, new Car( "Merca", 800) );
	registry.put( 6, new Car( "Honda", 2000 ) );
	registry.put( 4, new MotorCycle( "Fiat", 150 ) );
	registry.put( 3, new Car( "Toyota", 1200 ) );
	registry.put( 13, new MotorCycle( "Yamaha ", 200 ) );

	auto toDelete = registry.get( 6 );
	//registry.remove( toDelete );

	auto deleted = registry.get( 6 );
	if ( deleted ) {
		registry.put( 6, new Car( "Audi", 600 ) );
		registry.get( 6 )->printInformation();

	} else {
		std::cout << "Value at key 6 was deleted" << std::endl;
	}

}

int main() {
	
	// run our test
	test();

	// Wait for input
	std::cin.get();
}
