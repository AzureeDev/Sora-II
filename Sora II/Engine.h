#pragma once
#include "SDL.h"

namespace Lilac
{
	class Engine
	{
		// Members
	private:
		Lilac::SDL sdl_instance;
		bool running = true;
		
		// Methods
	public:
		Engine();
		Lilac::SDL& sdl() { return this->sdl_instance; };

	private:
		void init_globals();
		void init_base_assets();
		void update();
		void cleanup();
		
	};
}