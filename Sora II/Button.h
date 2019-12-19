#pragma once
#include <functional>
#include "UIElement.h"
#include "Texture.h"

namespace Lilac::UI
{
	class Button : public UIElement
	{
	private:
		std::shared_ptr<Lilac::Texture> button_texture = nullptr;
		SDL_Color button_color = { 255, 255, 255, 255 };
		std::function<void()> button_callback;

	public:
		Button() {};
		Button(std::string button_texture_path);

		bool mouse_inside();
		void set_color(const SDL_Color color);
		std::shared_ptr<Lilac::Texture> texture();
		void set_callback(std::function<void()> callback);
		virtual void event(const SDL_Event& event);
		virtual void render();
	};
}