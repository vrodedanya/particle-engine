#include "../include/simulator.hpp"
#include <string>
#include <iostream>
#include "../include/renderable.hpp"
#include "../include/dbhelper.h"

int lua_createWindow(lua_State* lvm)
{
	if (lua_gettop(lvm) != 7) return -1;
	Simulator* sim = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	std::string b{lua_tostring(lvm, 2)};
	int width = lua_tonumber(lvm, 3);
	int height = lua_tonumber(lvm, 4);
	int xpos = lua_tonumber(lvm, 5);
	int ypos = lua_tonumber(lvm, 6);
	bool isFullscreen = lua_toboolean(lvm, 7);
	sim->window = new Window(b.c_str(), width, height, xpos, ypos, isFullscreen);
	sim->window->add_toRender(&renderable::draw, sim->manager);
	return 0;
}

int lua_destroyWindow(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Simulator* sim = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	delete sim->window;
	sim->window = nullptr;
	return 0;
}

int lua_addParticle(lua_State* lvm)
{
	if (lua_gettop(lvm) != 7) return -1;
	Simulator* simulator = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	simulator->manager->add_particle(lua_tointeger(lvm, 2), lua_tointeger(lvm, 3), lua_tonumber(lvm, 4), lua_tonumber(lvm, 5), lua_tonumber(lvm, 6), lua_tonumber(lvm, 7));
	return 0;
}
int lua_drawCircle(lua_State* lvm)
{
	if (lua_gettop(lvm) != 4) return -1;
	Simulator* simulator = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	int x = lua_tointeger(lvm, 2);
	int y = lua_tointeger(lvm, 3);
	int radius = lua_tointeger(lvm, 4);
	simulator->window->add_toRender([x, y, radius](SDL_Renderer* renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				for (int i = y - radius ; i < y + radius ; i++)
				{
					for (int j = x - radius ; j < x + radius ; j++)
					{
						if (std::pow(x - j, 2) + std::pow(y - i, 2) <= std::pow(radius, 2))
						{
							SDL_RenderDrawPoint(renderer, j, i);
						}
					}
				}
			});
	return 0;
}

void Simulator::loop()
{
	while (event->isWork())
	{
		DBHelper::begin();
		event->update();
		manager->update();
		if (window) window->render();
		DBHelper::end();
	}
}
