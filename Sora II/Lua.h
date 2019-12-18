#pragma once
#include <lua.hpp>

namespace Lilac
{
	class Lua
	{
	private:
		lua_State* L = nullptr;

	public:
		Lua();
		~Lua();
		lua_State* state();
	};
}