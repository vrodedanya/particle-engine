#include <iostream>
#include "engine.hpp"

int main()
{
	Simulator sim("../source/script.lua");

	sim.loop();
	return 0;
}
