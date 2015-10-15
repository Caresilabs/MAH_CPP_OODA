#include "Main.h"


void Main::go() {
	aController.mainLoop();
}

static Main aMain;
void main() {
	aMain.go();
}