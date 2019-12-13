#include "Rendering.h"
#include "Globals.h"
#include "Vector2.h"

// Rescale the target rect to fit different 16:9 resolutions. Returns the passed rect.
SDL_Rect Lilac::Utils::Rendering::rescale(SDL_Rect& rect)
{
	const Vector2i workspace_size = Globals::engine->sdl().workspace_size();
	const Vector2i window_size = Globals::engine->sdl().window_size();

	rect.w = rect.w * (workspace_size.x / window_size.x);
	rect.h = rect.h * (workspace_size.y / window_size.y);

	return rect;
}
