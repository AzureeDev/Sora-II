#pragma once
#include <memory>
#include "Vector2.h"
#include "Texture.h"

namespace Lilac::Units
{
	class Unit
	{
	private:
		std::string unit_id = "";
		std::string unit_name = "";
		std::string unit_path = "";
		std::shared_ptr<Lilac::Texture> unit_texture = nullptr;	
		Vector2i unit_position = { 0, 0 };
		int unit_width = 0;
		int unit_height = 0;
		int unit_scale_multiplier = 1;
		int unit_sprite_size = 256;
		int unit_animation_speed = 125;
		int unit_animation_count = 0;
		int unit_current_sprite_id = 0;

	public:
		Unit() {};
		Unit(const std::string unit_id, const std::string unit_texture_path);
		virtual ~Unit();
		virtual void set_position(const Vector2i pos);
		void set_sprite_size(unsigned sprite_size);
		void set_scale_multiplier(int scale_multiplier);
		const Vector2i position() { return this->unit_position; };
		const int sprite_size() { return this->unit_sprite_size; };
		virtual void render();
	};
}