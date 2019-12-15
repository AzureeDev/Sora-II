#pragma once
#include "lua.hpp"

namespace Lilac
{
	class Lua
	{
	private:
		lua_State* lua_state = nullptr;

	public:
		Lua();
		lua_State* state();
		void fetch_error();
	};
}
	
