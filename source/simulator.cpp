#include "simulator.hpp"
#include <string>
#include <iostream>

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

void Simulator::loop()
{
	while (event->isWork())
	{
		event->update();
		if (window) window->render();
	}
}
