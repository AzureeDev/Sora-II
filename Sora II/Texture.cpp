#include "Texture.h"
#include <SDL_image.h>
#include "Globals.h"

Lilac::Texture::Texture(std::string texturePath) : Lilac::Asset<SDL_Texture*>(texturePath)
{
	this->load();
}

Lilac::Texture::~Texture()
{
	if (this->asset != nullptr)
	{
		SDL_DestroyTexture(this->asset);
		this->asset = nullptr;

		SDL_Log("Texture %s destroyed.", this->asset_name.c_str());
	}
}

/* Load the texture. Returns 1 on success, 0 on failure. */
int Lilac::Texture::load()
{
	SDL_RWops* rw = Globals::archive->open_file(this->asset_path);
	SDL_Surface* textureSurface = IMG_LoadTGA_RW(rw);

	if (textureSurface != nullptr)
	{
		SDL_SetSurfaceRLE(textureSurface, 1);

		/* Fill Texture Data */
		this->texture_data.w = textureSurface->w;
		this->texture_data.h = textureSurface->h;
		this->texture_data.clip_rect = textureSurface->clip_rect;
		this->texture_data.format = textureSurface->format;
		this->texture_data.pitch = textureSurface->pitch;
		this->texture_data.pixels = textureSurface->pixels;
		this->texture_data.userdata = textureSurface->userdata;
		this->texture_data.refcount = textureSurface->refcount;

		/* Create the asset */
		this->asset = SDL_CreateTextureFromSurface(Globals::engine->sdl().get_renderer(), textureSurface);

		/* Free the surface & raw file */
		SDL_FreeSurface(textureSurface);
		rw->close(rw);

		/* Return 1 on success or 0, with log, if it failed. */
		if (this->asset == nullptr)
		{
			SDL_Log("Lilac::Texture::load() - Error loading %s : %s", this->asset_path.c_str(), IMG_GetError());
			return 0;
		}
	}
	else
	{
		SDL_Log("Lilac::Texture::load() - Error creating surface %s : %s", this->asset_path.c_str(), IMG_GetError());
		SDL_FreeSurface(textureSurface);
		SDL_FreeRW(rw);
		return 0;
	}

	return 1;
}

const TextureData& Lilac::Texture::data()
{
	return this->texture_data;
}
