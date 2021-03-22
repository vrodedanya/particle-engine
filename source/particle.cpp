#include "particle.hpp"
#include "drawing.hpp"

void Particle::draw(SDL_Renderer* renderer)
{
	tbo::drawing::changeColor(renderer, color.r, color.g, color.b, color.a);
	tbo::drawing::point(renderer, position.x(), position.y());
}
