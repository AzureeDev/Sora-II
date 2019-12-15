#include "Lua.h"
#include "LuaWrapper.h"
#include <string>

Lilac::Lua::Lua()
{
	/*
	// Create the lua state and init the libraries
	this->lua_state = lua_open();
	luaL_openlibs(this->lua_state);

	int res = luaL_dofile(this->lua_state, "lib/hello.lua");

	if (res != LUA_OK)
	{
		this->fetch_error();
	}*/
}

lua_State* Lilac::Lua::state()
{
	return this->lua_state;
}

void Lilac::Lua::fetch_error()
{
	std::string message = lua_tostring(this->lua_state, -1);
	puts(message.c_str());
	lua_pop(this->lua_state, 1);
}
