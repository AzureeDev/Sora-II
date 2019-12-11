#pragma once
#include "Asset.h"

struct TextureData
{
	int w = 0;
	int h = 0;
	SDL_PixelFormat* format = nullptr;
	int pitch = 0;
	void* pixels = nullptr;
	void* userdata = nullptr;
	SDL_Rect clip_rect = {};
	int	refcount = 0;
};

namespace Lilac
{
	class Texture : public Lilac::Asset<SDL_Texture*>
	{
	private:
		// Texture data
		TextureData texture_data;

	public:
		Texture(std::string texturePath);
		virtual ~Texture();
		virtual int load();
		const TextureData& data();
	};
}