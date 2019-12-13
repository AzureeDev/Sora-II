#pragma once
#include <SDL_video.h>

namespace Lilac::Utils
{
	class Rendering
	{
	public:
		// Rescale the target rect to fit different 16:9 resolutions. Returns the passed rect.
		static SDL_Rect rescale(SDL_Rect& rect);
	};
}