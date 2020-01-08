#include "MusicManager.h"
#include "Globals.h"

Mix_Music* Lilac::MusicManager::current_music = nullptr;
double Lilac::MusicManager::current_repeat_time = 0.0;

void Lilac::MusicManager::play(const std::string music_path, const int repeats)
{
	MusicManager::current_music = Globals::assets->load_music("MusicManager_music", music_path)->get();
	Mix_FadeInMusic(MusicManager::current_music, repeats, 1500);
	Mix_VolumeMusic(35);
}

void Lilac::MusicManager::play_with_repeat(const std::string music_path, const double repeat_time)
{
	MusicManager::current_music = Globals::assets->load_music("MusicManager_music", music_path)->get();
	MusicManager::current_repeat_time = repeat_time;

	Mix_PlayMusic(MusicManager::current_music, 0);
	Mix_VolumeMusic(35);
	Mix_HookMusicFinished([]() 
		{
			MusicManager::repeat_current_at_time();
		}
	);
}

void Lilac::MusicManager::repeat_current_at_time()
{
	Mix_PlayMusic(MusicManager::current_music, 0);
	if (Mix_SetMusicPosition(MusicManager::current_repeat_time) == -1)
	{
		SDL_Log("ERROR Mix_SetMusicPosition: %s", Mix_GetError());
	}
}
