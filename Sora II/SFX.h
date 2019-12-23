#pragma once
#include "Asset.h"
#include <SDL_mixer.h>

namespace Lilac
{
	class SFX : public Asset<Mix_Chunk*>
	{
	public:
		SFX(const std::string sfx_path);
		virtual ~SFX();
		virtual int load();
	};
}