#include "window.hpp"
#include <algorithm>

bool operator==(const render_wrapper& first, const render_wrapper& second)
{
	return (first.function == second.function) && (first.object == second.object);
}


void Window::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for (auto& func : objects)
	{
		(func.object->*func.function)(renderer);
	}

	SDL_RenderPresent(renderer);
}

void Window::add_toRender(renderfunc function, renderable* obj)
{
	auto it = std::find(objects.begin(), objects.end(), render_wrapper(function, obj));
	if (it == objects.end())
	{	
		objects.push_back(render_wrapper(function, obj));
	}
	else
	{
		throw std::runtime_error("Already exist");
	}
}
