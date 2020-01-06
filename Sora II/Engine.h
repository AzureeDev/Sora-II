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
		bool cursor_visible = false;
		Lilac::Utils::TickTimer cap_timer;
		
		// Methods
	public:
		Engine();
		// Initialize engine
		void init_engine();
		// Load cursor and fonts here.
		void init_base_assets();
		// Sets the cursor visible or not.
		void set_cursor_state(const bool visible);
		// Free the memory and quit the game
		void quit();
		// Access to SDL component
		Lilac::SDL& sdl() { return this->sdl_instance; };

	private:
		void init_globals();
		void init_lua();
		void init_entry_scene();
		void update();
		void cleanup();
	};
}