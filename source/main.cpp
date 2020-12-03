#include <iostream>
#include "engine.hpp"


void funct(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawPoint(renderer, 300, 300);
}

int main()
{
	Simulator sim("../source/script.lua");

	sim.loop();
	return 0;
}
