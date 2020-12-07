#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "particle.hpp"
#include <vector>
#include "renderable.hpp"


class Manager : public renderable
{
private:
	std::vector<Particle*> particles;
public:
	explicit Manager(){}
	~Manager();

	void add_particle(int x, int y);

	void draw(SDL_Renderer* renderer) override
	{
		for (auto& particle : particles)
		{
			particle->draw(renderer);
		}
	}
};

#endif
