#include <iostream>
#include "../include/engine.hpp"

int main()
{
	Simulator sim("../scripts/script.lua");

	sim.loop();
	return 0;
}
