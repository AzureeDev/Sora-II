#include "Music.h"

Lilac::Music::Music(const std::string music_path) : Asset(music_path)
{
	this->load();
}

Lilac::Music::~Music()
{
	if (this->asset != nullptr)
	{
		Mix_FreeMusic(this->asset);
		SDL_Log("Music %s destroyed.", this->asset_name.c_str());
	}
}

int Lilac::Music::load()
{
	if (this->path_correct())
	{
		this->asset = Mix_LoadMUS(this->asset_path.c_str());
		return 1;
	}
	
	return 0;
}
