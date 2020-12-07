#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "particle.hpp"
#include <vector>
#include <string>
#include "renderable.hpp"


class Manager : public renderable
{
private:
	std::vector<Particle*> particles;
	std::string script;
public:
	explicit Manager(const std::string& update_script) : script(update_script) {}
	~Manager();

	void add_particle(int x, int y, double speed_x, double speed_y, double direction_x, double direction_y);

	void draw(SDL_Renderer* renderer) override
	{
		for (auto& particle : particles)
		{
			particle->draw(renderer);
		}
	}
	void update();
};

#endif
