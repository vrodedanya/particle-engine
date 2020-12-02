#include <iostream>
#include "engine.hpp"


void funct(SDL_Renderer* renderer)
{
	std::cout << "HERE" << std::endl;
}

int main()
{
	Window window("Test", 600, 600, 0, 0, false);
	
	window.add_toRender(funct);

	while(1)
	{
		window.render();
	}

	return 0;
}
