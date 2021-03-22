#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "vector2D.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "renderable.hpp"
#include "style.hpp"
#include <functional>

class Particle : public tbo::renderable
{
private:
public:
	Particle() {type = tbo::renderable::OTHER;}
	Vector2D way;
	Vector2D speed;
	Vector2D acceleration;
	Vector2D position;
	tbo::style::rgba color;

	void draw(tbo::renderer* renderer);
};

#endif
