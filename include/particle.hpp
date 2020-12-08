#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "vector2D.hpp"
#include <SDL2/SDL.h>
#include <string>

class Particle
{
private:
public:
	Particle() : position(Vector2D(0, 0)) {}
	Particle(int x, int y) : position(Vector2D(x, y)) {}
	Particle(int x, int y, double speed_x, double speed_y) : speed(Vector2D(speed_x, speed_y)), position(Vector2D(x, y)) {}
	Particle(int x, int y, double speed_x, double speed_y, double direction_x, double direction_y) : way(Vector2D(direction_x, direction_y)),speed(Vector2D(speed_x, speed_y)), position(Vector2D(x, y)) {}
	Particle(int x, int y, double speed_x, double speed_y, double direction_x, double direction_y, double acceleration_x, double acceleration_y) : way(Vector2D(direction_x, direction_y)),speed(Vector2D(speed_x, speed_y)), acceleration(Vector2D(acceleration_x, acceleration_y)), position(Vector2D(x, y)) {}
	Vector2D way;
	Vector2D speed;
	Vector2D acceleration;
	Vector2D position;

	void draw(SDL_Renderer* renderer);
};

#endif
