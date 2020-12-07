#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <SDL2/SDL.h>
#include "event.hpp"
#include "window.hpp"
#include "manager.hpp"

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

int lua_createWindow(lua_State* lvm);
int lua_destroyWindow(lua_State* lvm);
int lua_addParticle(lua_State* lvm);


class Simulator	
{
private:
	lua_State* lvm;
public:
	Window* window;
	Event* event;
	Manager manager;

	Simulator(const char* scriptName) : window(nullptr), event(new Event)
	{
		lvm = luaL_newstate();
		luaL_openlibs(lvm);
		if (luaL_dofile(lvm, scriptName) != LUA_OK)
		{
			throw std::runtime_error("Script " + static_cast<std::string>(scriptName) + " doesn't exist or something else! Please check");
		}
// Register C++ functions here
		lua_register(lvm, "_createWindow", lua_createWindow);
		lua_register(lvm, "_destroyWindow", lua_destroyWindow);
		lua_register(lvm, "_addParticle", lua_addParticle);

// Get lua functions here
		lua_getglobal(lvm, "script");
		if (lua_isfunction(lvm, -1))
		{
			lua_pushlightuserdata(lvm, this);
			lua_pcall(lvm, 1, 0, 0);
		}
	}
	~Simulator()
	{
		delete window;
		delete event;
	}

	void loop();
};


#endif
