#include "particle.hpp"

void Particle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderDrawPoint(renderer, position.x(), position.y());
}
