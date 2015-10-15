#pragma once

#include "Controller.h"

class Main {
public:
	Main() = default;

	void go();
	
private:
	Controller aController;
};

static Main aMain;
void main();

