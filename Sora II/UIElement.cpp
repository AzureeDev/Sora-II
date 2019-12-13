#include "UIElement.h"
#include "Globals.h"

void Lilac::UI::UIElement::set_position(Vector2i pos)
{
	/* Adapt pos to current resolution / workspace size */
	Vector2i new_pos = { 0, 0 };
	const Vector2i workspace_size = Globals::engine->sdl().workspace_size();
	const Vector2i window_size = Globals::engine->sdl().window_size();

	new_pos.x = pos.x * (workspace_size.x / window_size.x);
	new_pos.y = pos.y * (workspace_size.y / window_size.y);

	this->element_position = new_pos;
}
