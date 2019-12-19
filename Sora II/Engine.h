#pragma once
#include "SDL.h"
#include "Image.h"
#include "TickTimer.h"

namespace Lilac
{
	class Engine
	{
		// Members
	private:
		Lilac::SDL sdl_instance;
		std::shared_ptr<Lilac::UI::Image> cursor = nullptr;
		bool running = true;
		Lilac::Utils::TickTimer cap_timer;
		
		// Methods
	public:
		Engine();
		void init_engine();
		void quit();
		Lilac::SDL& sdl() { return this->sdl_instance; };

	private:
		void init_globals();
		void init_base_assets();
		void init_lua();
		void init_entry_scene();
		void update();
		void cleanup();
		
	};
}