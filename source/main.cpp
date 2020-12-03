#include <iostream>
#include "engine.hpp"


void funct(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawPoint(renderer, 300, 300);
}

int main()
{
	Simulator sim("Title", 600, 600, 0, 0, false);

	sim.loop();
	return 0;
}
