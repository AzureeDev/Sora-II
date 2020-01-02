#include "Lua.h"
#include "Globals.h"
#include <SDL_log.h>

Lilac::Lua::Lua()
{
	SDL_Log("Opening Lua...");
	this->L = lua_open();
	luaL_openlibs(this->L); // Base libs
}

Lilac::Lua::~Lua()
{
	SDL_Log("Closing Lua...");
	lua_close(this->L);
}

lua_State* Lilac::Lua::state()
{
	return this->L;
}
