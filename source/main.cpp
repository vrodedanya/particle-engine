#include <iostream>
#include "engine.hpp"


void funct(SDL_Renderer* renderer)
{
	std::cout << "HERE" << std::endl;
}

int main()
{
	Window window("Test", 600, 600, 0, 0, false);
	Event event;

	
	window.add_toRender(funct);

	while(event.isWork())
	{
		window.render();
		event.update();
	}

	return 0;
}
