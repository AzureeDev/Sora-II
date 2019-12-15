#include "LuaWrapper.h"
#include <SDL_log.h>

int lua_test(lua_State* state)
{
	SDL_Log("Called from Lua!!");
	return 0;
}
