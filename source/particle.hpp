#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "vector2D.hpp"
#include <SDL2/SDL.h>

class Particle
{
private:
public:
	Particle(int x, int y) : position(Vector2D(x, y)) {}
	Particle() {}
	Vector2D way;
	Vector2D speed;
	Vector2D position;

	void draw(SDL_Renderer* renderer);
};

#endif
