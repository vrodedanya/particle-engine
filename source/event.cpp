#include "event.hpp"

void Event::update()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isW = false;
		}
		if (event.type == SDL_KEYDOWN)
		{
			isW = false;
		}
	}
}
