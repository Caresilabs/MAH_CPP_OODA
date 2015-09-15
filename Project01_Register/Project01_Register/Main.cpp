#include <iostream>
#include "PtrList.h";
#include "Registry.h"

int main() {
	// Test class

	Registry<int, char> registry(3);
	registry.put(22, new char('A'));
	registry.put(1, new char('Y'));
	registry.put(5, new char('X'));
	registry.put(6, new char('G'));
	registry.put(13, new char('g'));
	registry.put(90, new char('2'));
	registry.put(155, new char('u'));

	auto toDelete = registry.get(6);
	registry.remove(toDelete);

	auto deleted = registry.get(6);
	if (deleted) {
		std::cout << *registry.get(6) << std::endl;
	} else {
		std::cout << "Value at key 6 was deleted" << std::endl;
	}

	// Wait for input
	std::cin.get();
}