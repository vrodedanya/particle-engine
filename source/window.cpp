#include "window.hpp"
#include <algorithm>

void Window::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for (auto& func : objects)
	{
		func(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Window::add_toRender(void(*ptr)(SDL_Renderer* renderer))
{
	auto it = std::find(objects.begin(), objects.end(), ptr);
	if (it == objects.end())
	{	
		objects.push_back(ptr);
	}
	else
	{
		throw std::runtime_error("Already exist");
	}
}
