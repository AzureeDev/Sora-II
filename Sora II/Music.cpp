#include "Music.h"
#include "Globals.h"

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
		SDL_RWops* rw = Globals::archive->open_file(this->asset_path);
		this->asset = Mix_LoadMUS_RW(rw, 1);
		return 1;
	}
	
	return 0;
}
