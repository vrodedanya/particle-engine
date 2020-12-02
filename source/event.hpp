#ifndef EVENT_HPP
#define EVENT_HPP

#include <SDL2/SDL.h>

class Event
{
private:
	SDL_Event event;
	bool isW;
public:
	explicit Event() : isW(true){}
	void update();

	bool isWork() const {return isW;}
	void set_isWork(bool isWork){isW = isWork;}
};

#endif
