#include "event.hpp"

#include <stdlib.h>

void Event::update()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isW = false;
		}
	}
}
