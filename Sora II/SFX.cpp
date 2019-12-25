#include "SFX.h"
#include "Globals.h"

Lilac::SFX::SFX(const std::string sfx_path) : Asset(sfx_path)
{
	this->load();
}

Lilac::SFX::~SFX()
{
	if (this->asset != nullptr)
	{
		Mix_FreeChunk(this->asset);
		SDL_Log("SFX %s destroyed.", this->asset_name.c_str());
	}
}

int Lilac::SFX::load()
{
	if (this->path_correct())
	{
		SDL_RWops* rw = Globals::archive->open_file(this->asset_path);
		this->asset = Mix_LoadWAV_RW(rw, 1);
		return 1;
	}

	return 0;
}
