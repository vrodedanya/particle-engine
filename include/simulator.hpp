#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "program.hpp"
#include "particle.hpp"
#include "lua_manager.hpp"

int lua_createWindow(lua_State* lvm);
int lua_addParticle(lua_State* lvm);

int lua_getCoords(lua_State* lvm);
int lua_getDirection(lua_State* lvm);
int lua_getSpeed(lua_State* lvm);
int lua_getAcceleration(lua_State* lvm);
int lua_setCoords(lua_State* lvm);
int lua_setDirection(lua_State* lvm);
int lua_setSpeed(lua_State* lvm);
int lua_setAcceleration(lua_State* lvm);
int lua_setColor(lua_State* lvm);
int lua_getCenterCoords(lua_State* lvm);
int lua_getWindowSize(lua_State* lvm);

int lua_getDelta(lua_State* lvm);

class Simulator	: public tbo::program
{
private:
	lua_State* lvm;
	std::string script;
	std::vector<Particle*> particles;
public:
	Simulator(const char* scriptName)
	{
		script = scriptName;
		lvm = luaL_newstate();
		luaL_openlibs(lvm);
		if (luaL_dofile(lvm, scriptName) != LUA_OK)
		{
			throw std::runtime_error("Script " + static_cast<std::string>(scriptName) + " doesn't exist or something else! Please check");
		}
// Register C++ functions here
		lua_register(lvm, "_createWindow", lua_createWindow);
		lua_register(lvm, "_setCoords", lua_setCoords);
		lua_register(lvm, "_setDirection", lua_setDirection);
		lua_register(lvm, "_setSpeed", lua_setSpeed);
		lua_register(lvm, "_setAcceleration", lua_setAcceleration);
		lua_register(lvm, "_setColor", lua_setColor);
		lua_register(lvm, "_getCoords", lua_getCoords);
		lua_register(lvm, "_getDirection", lua_getDirection);
		lua_register(lvm, "_getSpeed", lua_getSpeed);
		lua_register(lvm, "_getAcceleration", lua_getAcceleration);
		lua_register(lvm, "_getCenterCoords", lua_getCenterCoords);
		lua_register(lvm, "_getDelta", lua_getDelta);
		lua_register(lvm, "_addParticle", lua_addParticle);

// Get lua functions here
		lua_getglobal(lvm, "init");
		if (lua_isfunction(lvm, -1))
		{
			lua_pushlightuserdata(lvm, this);
			lua_pcall(lvm, 1, 0, 0);
		}
	}
	~Simulator()
	{
		for (auto& particle : particles)
		{
			delete particle;
		}
		lua_close(lvm);
	}
	
	Particle* addParticle(const char* window_name);

	void updateParticle(Particle* part);

	void update();
};


#endif
