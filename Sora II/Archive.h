#pragma once
#include "physfsrwops.h"
#include <SDL.h>
#include <string>

namespace Lilac
{
	class Archive
	{
	private:
		unsigned loaded_packages = 0;

	public:
		Archive();
		// Critical packages are packages you want to load as early as possible - fonts are there as text renderered with a nullptr font will crash the game (tofix)
		void load_critical_packages();
		// All other packages, sounds, music, ect
		void load_additional_packages();
		// Used by Assets, loads a file from the archive.
		SDL_RWops* open_file(const std::string path);
		
	private:
		void load_package(const std::string path);
	};
}