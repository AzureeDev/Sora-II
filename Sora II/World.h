#pragma once
#include <memory>
#include <string>
#include "Texture.h"

namespace Lilac
{
	class World
	{
	private:
		std::shared_ptr<Lilac::Texture> world_texture = nullptr;
		SDL_Color world_color = { 255, 255, 255, 255 };
		int scrolling_offset = 0;
		bool world_allow_scroll = true;
		float scroll_speed_multiplier = 1.0f;

	public:
		World();
		World(std::string world_id);
		void set_world_color(const SDL_Color color);
		void set_world_scroll_multiplier(const float mult);
		void set_world_scroll(const bool state);
		void render();
	};
}