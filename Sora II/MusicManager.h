#pragma once
#include <string>
#include <SDL_mixer.h>

namespace Lilac
{
	class MusicManager
	{
	private:
		static Mix_Music* current_music;
		static double current_repeat_time;

	public:
		// Play a music and repeat it on the loop point "repeat_time".
		static void play_with_repeat(const std::string music_path, const double repeat_time);
		// Callback that repeats the song for "play_with_repeat".
		static void repeat_current_at_time();
	};
}