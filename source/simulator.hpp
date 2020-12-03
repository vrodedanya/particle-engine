#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <SDL2/SDL.h>
#include "event.hpp"
#include "window.hpp"

class Simulator	
{
private:
public:
	Window* window;
	Event* event;

	Simulator(const char* window_name, unsigned window_width, unsigned window_height, int xpos, int ypos, bool isFullscreen) : window(new Window(window_name, window_width, window_height, xpos, ypos, isFullscreen)), event(new Event)
	{
	}
	Simulator(const char* window_name) : window(new Window(window_name)), event(new Event)
	{
	}
	~Simulator()
	{
		delete window;
		delete event;
	}

	void loop();

};

#endif
