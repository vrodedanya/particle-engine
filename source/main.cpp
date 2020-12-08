#include <iostream>
#include "../include/engine.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Format:\n./engine <script_name>" << std::endl;
		return 1;
	}
	Simulator sim(argv[1]);

	sim.loop();
	return 0;
}
