#include <iostream>
#include "PtrList.h";

int main() {
	PtrList<int> list(2);

	list.push_back(new int(5));

	std::cout << list[0] << std::endl;
}