#pragma once
#include "Asset.h"
#include "Font.h"

struct TextData
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
	class Text : public Lilac::Asset<SDL_Texture*>
	{
	private:
		std::string asset_current_text = "";
		TTF_Font* asset_font = nullptr;
		SDL_Color asset_text_color = { 255, 255, 255, 255 };
		TextData asset_text_data;
		int asset_text_max_width = 0;

		virtual int load();
		void create_text(SDL_Surface* text_surface);

	public:
		Text(std::string text, SDL_Color text_color, int max_width, std::shared_ptr<Lilac::Font> font = nullptr);
		virtual ~Text();
		TextData& data();
		void set_text(std::string text);
		void destroy();
	};
}