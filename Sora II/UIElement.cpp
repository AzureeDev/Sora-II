#include "UIElement.h"
#include "Globals.h"

void Lilac::UI::UIElement::set_position(Vector2i pos)
{
	this->element_position = pos;
}

void Lilac::UI::UIElement::set_x(int x)
{
	this->element_position.x = x;
}

void Lilac::UI::UIElement::set_y(int y)
{
	this->element_position.y = y;
}

void Lilac::UI::UIElement::event(const SDL_Event& event)
{
}