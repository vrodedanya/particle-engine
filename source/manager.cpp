#include "../include/manager.hpp"
#include <stdexcept>
#include "../include/dbhelper.h"
#include <iostream>

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
int lua_getDelta(lua_State* lvm)
{
	if (lua_gettop(lvm) != 0) return -1;
	lua_pushnumber(lvm, DBHelper::delta);
	return 1;
}
int lua_setCoords(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	particle->position.x() = lua_tonumber(lvm, 2);
	particle->position.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setDirection(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	particle->way.x() = lua_tonumber(lvm, 2);
	particle->way.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setSpeed(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	particle->speed.x() = lua_tonumber(lvm, 2);
	particle->speed.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setAcceleration(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	particle->acceleration.x() = lua_tonumber(lvm, 2);
	particle->acceleration.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_getCoords(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, particle->position.x());
	lua_pushnumber(lvm, particle->position.y());
	return 2;
}
int lua_getDirection(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, particle->way.x());
	lua_pushnumber(lvm, particle->way.y());
	return 2;
}
int lua_getSpeed(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, particle->speed.x());
	lua_pushnumber(lvm, particle->speed.y());
	return 2;
}
int lua_getAcceleration(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, particle->acceleration.x());
	lua_pushnumber(lvm, particle->acceleration.y());
	return 2;
}
/*
int lua_getNearestParticle(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* particle = static_cast<Particle*>(lua_touserdata(lvm, 1));

}
*/
Manager::~Manager()
{
	for (auto& particle : particles)
	{
		delete particle;
	}
}

void Manager::add_particle(int x, int y, double speed_x, double speed_y, double direction_x, double direction_y)
{
	particles.emplace_back(new Particle(x, y, speed_x, speed_y, direction_x, direction_y));
}

void Manager::update()
{
	lua_State* lvm = luaL_newstate();
	luaL_openlibs(lvm);
	lua_register(lvm, "_setCoords", lua_setCoords);
	lua_register(lvm, "_setDirection", lua_setDirection);
	lua_register(lvm, "_setSpeed", lua_setSpeed);
	lua_register(lvm, "_setAcceleration", lua_setAcceleration);
	lua_register(lvm, "_getCoords", lua_getCoords);
	lua_register(lvm, "_getDirection", lua_getDirection);
	lua_register(lvm, "_getSpeed", lua_getSpeed);
	lua_register(lvm, "_getAcceleration", lua_getAcceleration);
	lua_register(lvm, "_getDelta", lua_getDelta);
	
	for (auto& particle : particles)
	{
		if (luaL_dofile(lvm, script.c_str()) != LUA_OK)
		{
			throw std::runtime_error("Update script execute error");
		}
		
		lua_getglobal(lvm, "update");
		if (lua_isfunction(lvm, -1))
		{
			lua_pushlightuserdata(lvm, particle);
			lua_pcall(lvm, 1, 0, 0);
		}

		particle->position += particle->speed * particle->way.normalize() * DBHelper::delta;
	}
	lua_close(lvm);
}
