#include <iostream>
#include "Registry.h"
#include "Vehicle.h"

int main() {
	// Test class

	Registry<int, Vehicle> registry( 3 );
	registry.put( 22, new Vehicle( "Volvo", 700, 4 ) );
	registry.put( 1, new  Vehicle( "Volvo", 700, 4 ) );
	registry.put( 5, new Vehicle( "Volvo", 700, 4 ) );
	registry.put( 6, new Vehicle( "Volvo", 700, 4 ) );
	registry.put( 13, new  Vehicle( "Volvo", 700, 4 ) );
	registry.put( 90, new Vehicle( "Volvo", 700, 4 ) );
	registry.put( 155, new  Vehicle( "Volvo", 700, 4 ) );

	auto toDelete = registry.get( 6 );
	//registry.remove( toDelete );

	auto deleted = registry.get( 6 );
	if ( deleted ) {
		//std::cout << *registry.get( 6 ) << std::endl;
		registry.get( 6 )->printInformation();
	} else {
		std::cout << "Value at key 6 was deleted" << std::endl;
	}

	
	
	// Wait for input
	std::cin.get();
}