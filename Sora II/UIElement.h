#pragma once
#include <string>
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
		virtual Vector2i position() { return this->element_position; };
		virtual void render() {};
	};
}
	