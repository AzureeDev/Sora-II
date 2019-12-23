#include "SFX.h"

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
		this->asset = Mix_LoadWAV(this->asset_path.c_str());
		return 1;
	}

	return 0;
}
