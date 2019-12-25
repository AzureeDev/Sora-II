#include "World.h"
#include "Globals.h"

Lilac::World::World()
{
}

Lilac::World::World(std::string world_id)
{
	this->world_texture = Globals::assets->load_texture(world_id, "worlds/" + world_id);
}

void Lilac::World::set_world_color(const SDL_Color color)
{
	this->world_color.r = color.r;
	this->world_color.g = color.g;
	this->world_color.b = color.b;
}

void Lilac::World::set_world_scroll_multiplier(const float mult)
{
	this->scroll_speed_multiplier = mult;
}

void Lilac::World::set_world_scroll(const bool state)
{
	this->world_allow_scroll = state;
}

void Lilac::World::render()
{
	if (this->world_texture == nullptr)
	{
		return;
	}

	const int ws_width = Globals::engine->sdl().workspace_size().x;
	const int ws_height = Globals::engine->sdl().workspace_size().y;

	this->scrolling_offset -= (1 * this->scroll_speed_multiplier);

	if (this->scrolling_offset < -ws_width)
	{
		this->scrolling_offset = 0;
	}

	const SDL_Rect r_world = { this->scrolling_offset, 0, ws_width, ws_height };
	const SDL_Rect r_world2 = { this->scrolling_offset + ws_width, 0, ws_width, ws_height };
	
	SDL_SetTextureBlendMode(this->world_texture->get(), SDL_BLENDMODE_BLEND);
	SDL_SetTextureColorMod(this->world_texture->get(), this->world_color.r, this->world_color.g, this->world_color.b);
	SDL_SetTextureAlphaMod(this->world_texture->get(), this->world_color.a);

	if (this->world_allow_scroll)
	{
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->world_texture->get(), NULL, &r_world);
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->world_texture->get(), NULL, &r_world2);
	}
	else
	{
		const SDL_Rect r_world_static = { 0, 0, ws_width, ws_height };
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->world_texture->get(), NULL, &r_world_static);
	}
}
