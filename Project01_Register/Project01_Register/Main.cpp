#include <iostream>
#include "Registry.h"
#include "Vehicle.h"

void test() {
	// Test class

	Registry<int, Vehicle> registry( 3 );
	registry.put( 22, new Vehicle( "Merca", 800, 4 ) );
	registry.put( 1, new Vehicle( "Honda", 2000, 4 ) );
	registry.put( 6, new Vehicle( "Fiat", 150, 2 ) );
	registry.put( 3, new Vehicle( "Toyota", 1200, 4 ) );

	auto toDelete = registry.get( 6 );
	//registry.remove( toDelete );

	auto deleted = registry.get( 6 );
	if ( deleted ) {
		//std::cout << *registry.get( 6 ) << std::endl;
		registry.put( 6, new Vehicle( "Audi", 600, 4 ) );
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
