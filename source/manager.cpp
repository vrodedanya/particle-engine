#include "manager.hpp"

Manager::~Manager()
{
	for (auto& particle : particles)
	{
		delete particle;
	}
}

void Manager::add_particle(int x, int y)
{
	particles.emplace_back(new Particle(x, y));
}


