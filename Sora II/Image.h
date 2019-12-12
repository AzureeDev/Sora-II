#pragma once
#include <memory>
#include "UIElement.h"
#include "Texture.h"

namespace Lilac::UI
{
	class Image : public Lilac::UI::UIElement
	{
	protected:
		std::shared_ptr<Lilac::Texture> image_texture = nullptr;

	public:
		Image(std::string path);
		std::shared_ptr<Lilac::Texture> texture();
		void set_position(const Vector2i pos);
		void rescale(SDL_Rect& rect);
		virtual void render();
	};
}
