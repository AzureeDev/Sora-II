#pragma once
#include <string>
#include <SDL_events.h>
#include "Vector2.h"

namespace Lilac::UI
{
	class UIElement
	{
	protected:
		Vector2i element_position = { 0, 0 };
		int element_width = 0;
		int element_height = 0;

	public:
		virtual void set_position(Vector2i pos); // Set the X Y position
		virtual void set_x(int x); // Set only the X coordinates
		virtual void set_y(int y); // Set only the Y coordinates
		virtual const int width() const; // Returns the element's width
		virtual const int height() const; // Returns the element's height
		virtual const Vector2i top() const; // Position on top of the element
		virtual const Vector2i bottom() const; // Position on bottom of the element
		virtual const Vector2i right() const; // Position on right of the element
		virtual const Vector2i left() const; // Position on left of the element
		virtual const Vector2i position() const { return this->element_position; }; // Return the position
		virtual void event(const SDL_Event& event);
		virtual void render() {};
	};
}
	