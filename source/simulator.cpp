#include "simulator.hpp"
#include <string>
#include <iostream>
#include "time.hpp"
#include <algorithm>

int lua_createWindow(lua_State* lvm)
{
	if (lua_gettop(lvm) != 7) return -1;
	Simulator* sim = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	std::string b{lua_tostring(lvm, 2)};
	int width = lua_tonumber(lvm, 3);
	int height = lua_tonumber(lvm, 4);
	int xpos = lua_tonumber(lvm, 5);
	int ypos = lua_tonumber(lvm, 6);
	sim->add_window(b.c_str(), b.c_str(), width, height, xpos, ypos);
	return 0;
}

int lua_getCoords(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, part->position.x());
	lua_pushnumber(lvm, part->position.y());
	return 2;
}
int lua_getDirection(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, part->way.x());
	lua_pushnumber(lvm, part->way.y());
	return 2;
}
int lua_getSpeed(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, part->speed.x());
	lua_pushnumber(lvm, part->speed.y());
	return 2;
}
int lua_getAcceleration(lua_State* lvm)
{
	if (lua_gettop(lvm) != 1) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	lua_pushnumber(lvm, part->acceleration.x());
	lua_pushnumber(lvm, part->acceleration.y());
	return 2;
}
int lua_setCoords(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	part->position.x() = lua_tonumber(lvm, 2);
	part->position.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setDirection(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	part->way.x() = lua_tonumber(lvm, 2);
	part->way.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setSpeed(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	part->speed.x() = lua_tonumber(lvm, 2);
	part->speed.y() = lua_tonumber(lvm, 3);
	return 0;
}
int lua_setAcceleration(lua_State* lvm)
{
	if (lua_gettop(lvm) != 3) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	part->acceleration.x() = lua_tonumber(lvm, 2);
	part->acceleration.y() = lua_tonumber(lvm, 3);
	return 0;
}

int lua_setColor(lua_State* lvm)
{
	if (lua_gettop(lvm) != 5) return -1;
	Particle* part = static_cast<Particle*>(lua_touserdata(lvm, 1));
	part->color.r = lua_tonumber(lvm, 2);
	part->color.g = lua_tonumber(lvm, 3);
	part->color.b = lua_tonumber(lvm, 4);
	part->color.a = lua_tonumber(lvm, 5);
	return 0;
}

int lua_getDelta(lua_State* lvm)
{
	lua_pushnumber(lvm,tbo::time::timerange::get_delta());
	return 1;
}

int lua_getCenterCoords(lua_State* lvm)
{
	if (lua_gettop(lvm) != 2) return -1;
	Simulator* sim = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	std::string str = lua_tostring(lvm, 2);
	tbo::window* window = sim->get_window(str.c_str());
	if (window == nullptr) return 0;
	lua_pushnumber(lvm, sim->get_window(str.c_str())->get_style().size.width / 2);
	lua_pushnumber(lvm, sim->get_window(str.c_str())->get_style().size.height / 2);
	return 2;
}

int lua_addParticle(lua_State* lvm)
{
	if (lua_gettop(lvm) != 2) return -1;
	Simulator* sim = static_cast<Simulator*>(lua_touserdata(lvm, 1));
	Particle* buf = sim->addParticle(lua_tostring(lvm, 2));
	lua_pushlightuserdata(lvm, buf);
	return 1;
}

void Simulator::update()
{
	for (auto& particle : particles)
	{
		updateParticle(particle);
	}
}

void Simulator::updateParticle(Particle* particle)
{
	lua_getglobal(lvm, "update");
	if (lua_isfunction(lvm, -1))
	{
		lua_pushlightuserdata(lvm, this);
		lua_pushlightuserdata(lvm, particle);
		lua_pcall(lvm, 2, 0, 0);			
	}
	particle->position += particle->speed * particle->way.normalize() * tbo::time::timerange::get_delta();
}

Particle* Simulator::addParticle(const char* window_name)
{
	Particle* buf = new Particle();
	particles.emplace_back(buf);
	get_window(window_name)->add_object(buf);	
	return buf;
}
