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
		std::string image_path = "";
		SDL_Color image_color = { 255, 255, 255, 255 };
		int image_height = 0;
		int image_width = 0;
		SDL_RendererFlip image_flip = SDL_RendererFlip::SDL_FLIP_NONE;
		Vector2i image_custom_size = { 0, 0 };
		bool scrolling = false;
		TextureScroll scroll_state = TextureScroll::ToRight;
		float scroll_speed = 1.0f;
		int scroll_offset = 0;

	public:
		Image() {};
		Image(std::string path);
		void set_texture(std::string path);
		std::shared_ptr<Lilac::Texture> texture();
		void set_color(const SDL_Color color, const Uint8 alpha = 255);
		void set_alpha(const Uint8 alpha);
		void set_scroll(const bool state, const TextureScroll scroll_direction = TextureScroll::ToRight, const float speed = 1.0f);
		void set_custom_size(const Vector2i size);
		void set_flip(const SDL_RendererFlip flip);
		const Vector2i top();
		const Vector2i bottom();
		const Vector2i right();
		const Vector2i left();
		const Vector2i custom_size() const;
		virtual void render();	
	};
}