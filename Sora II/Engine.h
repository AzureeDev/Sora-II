#pragma once
#include "SDL.h"
#include "Image.h"

namespace Lilac
{
	class Engine
	{
		// Members
	private:
		Lilac::SDL sdl_instance;
		std::shared_ptr<Lilac::UI::Image> cursor = nullptr;
		bool running = true;
		
		// Methods
	public:
		Engine();
		Lilac::SDL& sdl() { return this->sdl_instance; };

	private:
		void init_globals();
		void init_base_assets();
		void init_entry_scene();
		void update();
		void cleanup();
		
	};
}