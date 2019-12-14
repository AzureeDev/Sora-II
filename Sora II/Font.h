#pragma once
#include "Asset.h"
#include <SDL_ttf.h>

namespace Lilac
{
	class Font : public Lilac::Asset<TTF_Font*>
	{
	private:
		int asset_font_ptsize = 14;

	public:
		Font(std::string asset_path, int ptsize = 14);
		virtual ~Font();
		virtual int load();
	};
}