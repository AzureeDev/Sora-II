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
		virtual void set_position(Vector2i pos);
		virtual void set_x(int x);
		virtual void set_y(int y);
		virtual Vector2i position() { return this->element_position; };
		virtual void event(const SDL_Event& event);
		virtual void render() {};
	};
}
	