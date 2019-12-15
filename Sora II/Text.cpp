#include "Text.h"
#include <SDL_ttf.h>
#include "Globals.h"

Lilac::Text::Text(std::string text, SDL_Color text_color, int max_width, std::shared_ptr<Lilac::Font> font) : Lilac::Asset<SDL_Texture*>("TEXT_ASSET")
{
	this->asset_current_text = text;
	this->asset_text_color = text_color;
	this->asset_text_max_width = max_width;

	if (font == nullptr)
	{
		font = Globals::assets->get_font("escom24");
	}

	this->asset_font = font->get();
	
	this->load();
}

Lilac::Text::~Text()
{
	this->destroy();
}

int Lilac::Text::load()
{
	if (!this->asset_current_text.empty())
	{
		SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(this->asset_font, this->asset_current_text.c_str(), this->asset_text_color, this->asset_text_max_width);
		this->create_text(surface);
		SDL_FreeSurface(surface);

		return 1;
	}

	return 0;
}

void Lilac::Text::create_text(SDL_Surface* text_surface)
{
	if (text_surface != nullptr)
	{
		this->asset = SDL_CreateTextureFromSurface(Globals::engine->sdl().get_renderer(), text_surface);

		this->asset_text_data.clip_rect = text_surface->clip_rect;
		this->asset_text_data.format = text_surface->format;
		this->asset_text_data.w = text_surface->w;
		this->asset_text_data.h = text_surface->h;
		this->asset_text_data.pitch = text_surface->pitch;
		this->asset_text_data.pixels = text_surface->pixels;
		this->asset_text_data.refcount = text_surface->refcount;
		this->asset_text_data.userdata = text_surface->userdata;
	}
}

TextData& Lilac::Text::data()
{
	return this->asset_text_data;
}

void Lilac::Text::set_text(std::string text)
{
	this->destroy();
	
	if (!text.empty())
	{
		this->asset_current_text = text;

		SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(this->asset_font, this->asset_current_text.c_str(), this->asset_text_color, this->asset_text_max_width);
		this->create_text(surface);

		SDL_FreeSurface(surface);
	}
}

void Lilac::Text::destroy()
{
	if (this->asset != nullptr)
	{
		SDL_Log("Text ' %s ' destroyed", this->asset_current_text.c_str());
		SDL_DestroyTexture(this->asset);
		this->asset = nullptr;
	}
}
