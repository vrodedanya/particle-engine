#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "program.hpp"
#include "lua.hpp"

class Simulator	: public tbo::program
{
private:
	lua_State* lvm;
public:
	Simulator(const char* scriptName)
	{
		lvm = luaL_newstate();
		luaL_openlibs(lvm);
		if (luaL_dofile(lvm, scriptName) != LUA_OK)
		{
			throw std::runtime_error("Script " + static_cast<std::string>(scriptName) + " doesn't exist or something else! Please check");
		}
// Register C++ functions here

// Get lua functions here
	}
	~Simulator()
	{
	}
	
	void update();
};


#endif
