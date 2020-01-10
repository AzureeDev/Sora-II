#include "UIElement.h"
#include "Globals.h"

void Lilac::UI::UIElement::set_position(const Vector2i pos)
{
	this->element_position = pos;
}

void Lilac::UI::UIElement::set_x(const int x)
{
	this->element_position.x = x;
}

void Lilac::UI::UIElement::set_y(const int y)
{
	this->element_position.y = y;
}

const int Lilac::UI::UIElement::width() const
{
	return this->element_width;
}

const int Lilac::UI::UIElement::height() const
{
	return this->element_height;
}

const Vector2i Lilac::UI::UIElement::top() const
{
	return this->element_position - Vector2i(0, this->element_height);
}

const Vector2i Lilac::UI::UIElement::bottom() const
{
	return this->element_position + Vector2i(0, this->element_height);
}

const Vector2i Lilac::UI::UIElement::right() const
{
	return this->element_position + Vector2i(this->element_width, 0);
}

const Vector2i Lilac::UI::UIElement::left() const
{
	return this->element_position - Vector2i(this->element_width, 0);
}

void Lilac::UI::UIElement::event(const SDL_Event& event)
{
}

void Lilac::UI::UIElement::update(const float dt)
{
}
