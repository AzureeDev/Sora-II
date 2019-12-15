#include "Font.h"

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
	this->asset = TTF_OpenFont(this->asset_path.c_str(), this->asset_font_ptsize);

	if (this->asset != nullptr)
	{
		return 1;
	}

	return 0;
}
