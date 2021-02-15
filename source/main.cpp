#include <iostream>
#include "../include/engine.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Format:\n./engine <script_name>" << std::endl;
		return 1;
	}

	tbo::logger::set_priority(tbo::logger::MEDIUM_PRIORITY);

	Simulator sim(argv[1]);

	return sim.loop();
}
