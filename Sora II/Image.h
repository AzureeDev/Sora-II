#pragma once
#include <memory>
#include "UIElement.h"
#include "Texture.h"

namespace Lilac::UI
{
	class Image : public Lilac::UI::UIElement
	{
	public:
		enum class TextureScroll {
			ToLeft,
			ToRight
		};

	protected:
		std::shared_ptr<Lilac::Texture> image_texture = nullptr;
		SDL_Color image_color = { 255, 255, 255, 255 };
		bool scrolling = false;
		TextureScroll scroll_state = TextureScroll::ToRight;
		float scroll_speed = 1.0f;
		int scroll_offset = 0;

	public:
		Image() {};
		Image(std::string path);
		std::shared_ptr<Lilac::Texture> texture();
		void set_color(const SDL_Color color);
		void set_alpha(const Uint8 alpha);
		void set_scroll(const bool state, const TextureScroll scroll_direction = TextureScroll::ToRight, const float speed = 1.0f);
		virtual void render();	
	};
}