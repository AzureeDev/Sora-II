#include "Unit.h"
#include "Globals.h"

Lilac::Units::Unit::Unit(const std::string unit_texture_path)
{
	this->unit_name = std::filesystem::path(unit_texture_path).filename().generic_u8string();
	this->unit_path = unit_texture_path;
	this->unit_texture = Globals::assets->load_texture("UNIT_" + unit_texture_path, unit_texture_path);

	this->unit_width = this->unit_texture->data().w;
	this->unit_height = this->unit_texture->data().h;
}

Lilac::Units::Unit::~Unit()
{
	Globals::assets->unload_texture("UNIT_" + this->unit_path);
}

void Lilac::Units::Unit::set_position(const Vector2i pos)
{
	this->unit_position = pos;
}

void Lilac::Units::Unit::render()
{
	
}
