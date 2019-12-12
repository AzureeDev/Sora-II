#pragma once
#include <SDL.h>
#include "Vector2.h"

namespace Lilac
{
	class SDL
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		Vector2i windowSize = {};
		Vector2i workspaceSize = { 1920, 1080 };

	public:
		SDL();
		void create_window();
		void create_mixer();
		void create_ttf();
		SDL_Window* get_window() { return this->window; };
		SDL_Renderer* get_renderer() { return this->renderer; };
		const Vector2i window_size() { return this->windowSize; };
		const Vector2i workspace_size() { return this->workspaceSize;  }
		void destroy();
	};
}
