#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <stdexcept>
#include <vector>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<void(*)(SDL_Renderer* renderer)> objects;
public:
	Window(const char* title, unsigned width, unsigned height, int x, int y, bool IsFullscreen)
	{
		if (!SDL_WasInit(SDL_INIT_EVERYTHING)) SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow(title, x, y, width, height, IsFullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	Window(const char* title) // fullscreen and desktop resolution
	{
		if (!SDL_WasInit(SDL_INIT_EVERYTHING)) SDL_Init(SDL_INIT_EVERYTHING);
		SDL_DisplayMode dm = {SDL_PIXELFORMAT_UNKNOWN, 0, 0, 0, 0 };

		if (SDL_GetDisplayMode(0, 0, &dm) != 0)
		{
			throw std::runtime_error(SDL_GetError());
		}

		window = SDL_CreateWindow(title, 0, 0, dm.w, dm.h, SDL_WINDOW_FULLSCREEN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	~Window()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	void add_toRender(void(*ptr)(SDL_Renderer* renderer));

	void render();

};

#endif
