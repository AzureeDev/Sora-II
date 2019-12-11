#pragma once
#include <SDL.h>

namespace Lilac
{
	class SDL
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

	public:
		SDL();
		void create_window();
		void create_mixer();
		void create_ttf();
		SDL_Window* get_window() { return this->window; };
		SDL_Renderer* get_renderer() { return this->renderer; };
		void destroy();
	};
}
