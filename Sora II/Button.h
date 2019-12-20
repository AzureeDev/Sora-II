#pragma once
#include <functional>
#include "UIElement.h"
#include "Texture.h"

namespace Lilac::UI
{
	class Button : public UIElement
	{
	public:
		enum class ButtonAnimation {
			None,
			RightSlide
		};

	private:
		std::shared_ptr<Lilac::Texture> button_texture = nullptr;
		SDL_Color button_color = { 255, 255, 255, 255 };
		SDL_Color button_highlight_color = { 255, 255, 255, 255 };
		SDL_Color button_disabled_color = { 255, 255, 255, 150 };
		std::function<void()> button_callback;
		std::function<void()> button_out_callback;
		ButtonAnimation button_anim = ButtonAnimation::None;
		Vector2i button_custom_size = { 0, 0 };
		bool button_enabled = true;
		int button_anim_original_x = 0;
		int button_anim_max_x = 0;

	public:
		Button() {};
		Button(std::string button_texture_path);

		virtual void set_position(Vector2i pos);
		bool mouse_inside();
		void set_animation(const ButtonAnimation anim);
		void set_color(const SDL_Color color);
		void set_enabled(const bool state);
		void set_custom_size(const Vector2i size);
		const bool enabled();
		void set_highlight_color(const SDL_Color color);
		void set_disabled_color(const SDL_Color color);
		std::shared_ptr<Lilac::Texture> texture();
		void set_callback(std::function<void()> callback);
		void set_out_callback(std::function<void()> callback);
		const Vector2i custom_size();
		virtual void event(const SDL_Event& event);
		virtual void render();
	};
}