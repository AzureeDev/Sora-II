#include "UIElement.h"
#include "Globals.h"

void Lilac::UI::UIElement::set_position(Vector2i pos)
{
	this->element_position = pos;
}

void Lilac::UI::UIElement::event(const SDL_Event& event)
{
}
