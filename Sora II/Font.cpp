#include "Font.h"
#include "Globals.h"

Lilac::Font::Font(std::string asset_path, int ptsize) : Lilac::Asset<TTF_Font*>(asset_path)
{
	this->asset_font_ptsize = ptsize;

	this->load();
}

Lilac::Font::~Font()
{
	if (this->asset != nullptr)
	{
		TTF_CloseFont(this->asset);
		this->asset = nullptr;

		SDL_Log("Font %s destroyed.", this->asset_name.c_str());
	}
}

int Lilac::Font::load()
{
	SDL_RWops* rw = Globals::archive->open_file(this->asset_path);
	this->asset = TTF_OpenFontRW(rw, 1, this->asset_font_ptsize);

	if (this->asset != nullptr)
	{
		return 1;
	}

	return 0;
}
