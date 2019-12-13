#pragma once
#include <memory>
#include "Vector2.h"
#include "Texture.h"

namespace Lilac::Units
{
	class Unit
	{
	private:
		std::string unit_name = "";
		std::string unit_path = "";
		std::shared_ptr<Lilac::Texture> unit_texture = nullptr;	
		Vector2i unit_position = { 0, 0 };
		int unit_width = 0;
		int unit_height = 0;

	public:
		Unit(const std::string unit_texture_path);
		virtual ~Unit();
		virtual void set_position(const Vector2i pos);
		const Vector2i position() { return this->unit_position; };
		virtual void render();
	};
}