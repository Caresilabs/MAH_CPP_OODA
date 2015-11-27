#pragma once

class NetworkException
{
public:
	char* error = "Could not connect to internet.";
	NetworkException() = default;
};
