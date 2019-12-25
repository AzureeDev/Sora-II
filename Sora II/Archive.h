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
		SDL_RWops* open_file(const std::string path);
		
	private:
		void load_package(const std::string path);
	};
}