#pragma once

/* Include base libraries for scenes */
#include <SDL.h>
#include <vector>
#include <string>

#include "UIElement.h"

namespace Lilac {
	class Scene
	{
	public:
		virtual void init();						// Executed on scene creation
		virtual void update(const float dt);		// Executed each frames, put logic in there, as well of inserting elements
	};
}