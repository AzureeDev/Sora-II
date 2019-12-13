#include "Unit.h"
#include "Globals.h"

Lilac::Units::Unit::Unit(const std::string unit_id, const std::string unit_texture_path)
{
	this->unit_id = unit_id;
	this->unit_name = std::filesystem::path(unit_texture_path).filename().generic_u8string();
	this->unit_path = unit_texture_path;
	this->unit_texture = Globals::assets->load_texture("UNIT_" + unit_id, unit_texture_path);

	this->unit_width = this->unit_texture->data().w;
	this->unit_height = this->unit_texture->data().h;

	this->unit_animation_count = this->unit_width / this->unit_sprite_size;
}

Lilac::Units::Unit::~Unit()
{
	Globals::assets->unload_texture("UNIT_" + this->unit_id);
}

void Lilac::Units::Unit::set_position(const Vector2i pos)
{
	this->unit_position = pos;
}

void Lilac::Units::Unit::set_sprite_size(unsigned sprite_size)
{
	// Fallback to default value if the sprite size is too high
	sprite_size = sprite_size > 2048 ? 256 : sprite_size;

	this->unit_sprite_size = sprite_size;
}

void Lilac::Units::Unit::render()
{
	SDL_Rect dest_rect = this->unit_texture->data().clip_rect;
	SDL_Rect src_rect = { 0, 0, 0, 0 };
	dest_rect.x = this->unit_position.x;
	dest_rect.y = this->unit_position.y;
	dest_rect.w = this->unit_sprite_size;
	dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);

	// Sprite animation
	const int ticks = SDL_GetTicks();

	if (this->unit_animation_count > 0)
	{
		this->unit_current_sprite_id = (ticks / this->unit_animation_speed) % this->unit_animation_count;
		src_rect = { this->unit_sprite_size * this->unit_current_sprite_id, 0, this->unit_sprite_size, this->unit_sprite_size };
	}

	SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->unit_texture->get(), &src_rect, &dest_rect);
}
