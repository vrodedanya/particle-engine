#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP
#include <vector>

class renderable
{
private:
public:
	virtual void draw(SDL_Renderer* renderer){}
};
#endif
