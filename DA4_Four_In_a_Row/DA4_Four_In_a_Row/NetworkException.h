#pragma once

class NetworkException
{
public:

	NetworkException() = default;

	char* error = "Could not connect to internet.";

	/* Disable copy constructor and assignment operator*/
	NetworkException(const NetworkException& rhs) = delete;
	NetworkException& operator=(const NetworkException& rhs) = delete;
};
