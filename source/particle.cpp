#include "particle.hpp"

void Particle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, position.x(), position.y());
}
