#include "Archive.h"

Lilac::Archive::Archive()
{
}

void Lilac::Archive::load_critical_packages()
{
	this->load_package("packages/fonts.pak");
}

void Lilac::Archive::load_additional_packages()
{
	this->load_package("packages/textures.pak");
	this->load_package("packages/musics.pak");
}

SDL_RWops* Lilac::Archive::open_file(std::string path)
{
	SDL_RWops* raw = PHYSFSRWOPS_openRead(path.c_str());

	if (raw != nullptr)
	{
		return raw;
	}

	SDL_Log("Couldn't open file from archive: %s", path.c_str());
	return nullptr;
}

void Lilac::Archive::load_package(const std::string path)
{
	if (PHYSFS_mount(path.c_str(), NULL, 1) == 0)
	{
		SDL_Log("ERROR MOUNTING DATA PACKAGE! %s", PHYSFS_getLastError());
	}
	else
	{
		SDL_Log("Loaded package: %s", path.c_str());
		this->loaded_packages++;
	}
}
