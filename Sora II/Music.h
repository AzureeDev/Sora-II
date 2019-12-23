#pragma once
#include "Asset.h"
#include <SDL_mixer.h>

namespace Lilac
{
	class Music : public Asset<Mix_Music*>
	{
	public:
		Music(const std::string music_path);
		virtual ~Music();
		virtual int load();
	};
}
	

