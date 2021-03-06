#include <iostream>
#include "Registry.h"
#include "Vehicle.h"
#include "Car.h"
#include "MotorCycle.h"

// DEBUG
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


// ============================
// Let's do some basic testing!
// ============================
void test() {

	/// Arrange

	Registry<int, Vehicle> registry( 3 ); // Show that it can grow
	registry.put( 22, new Car( "Merca", 800 ) );
	registry.put( 6, new Car( "Honda", 2000 ) );
	registry.put( 4, new MotorCycle( "Fiat", 150 ) );
	registry.put( 3, new Car( "Toyota", 1200 ) );
	registry.put( 13, new MotorCycle( "Yamaha ", 200 ) );


	/// Act

	auto key3 = registry.get( 3 ); // Get key #3
	auto key13 = registry.get( 13 ); // Get key #13

	std::cout << "Remove Key #3, Toyota" << std::endl;
	registry.remove( key3 ); // Remove

	std::cout << "Replace Yamaha with with an Audi. Yamaha is expected to be deleted" << std::endl;
	registry.put( 13, new Car( "Audi", 600 ) ); // Replace


	/// Assert

	if ( registry.get( 3 ) ) {
		// This should not be called
		std::cout << "Key #3 failed to delete" << std::endl;
	} else {
		std::cout << "Key #3 was correctly deleted" << std::endl;
	}

	std::cout << "We print our replaced Yamaha with an Audi, expect Audi as an output." << std::endl;
	registry.get( 13 )->printInformation(); // We print


	Registry<int, Vehicle> copy( registry );

	Registry<int, Vehicle> copy2 = copy;
	//copy2 = copy;

	std::cout << "The Registry should go out of scope! Expect 12 (4*3 because we copied twice) objects to get destroyed:" << std::endl;
}

int main() {
	new int;

	// Run our test
	test();

	// Wait for input
	std::cin.get();
	
	// Lastly we display all mem leaks
	_CrtDumpMemoryLeaks();
}
