#pragma once
#include <string>
#include "Vector2.h"

namespace Lilac::UI
{
	class UIElement
	{
	protected:
		std::string element_name;
		Vector2i element_position = { 0, 0 };
		int element_width = 0;
		int element_height = 0;

	public:
		virtual void render() = 0;
	};
}
	