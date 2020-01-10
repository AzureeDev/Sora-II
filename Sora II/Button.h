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
		std::string button_id = "";
		std::shared_ptr<Lilac::Texture> button_texture = nullptr;
		SDL_Color button_color = { 255, 255, 255, 255 };
		SDL_Color button_highlight_color = { 255, 255, 255, 255 };
		SDL_Color button_disabled_color = { 255, 255, 255, 150 };
		std::function<void()> button_callback;
		std::function<void()> button_out_callback;
		std::function<void()> button_on_hover_callback;
		ButtonAnimation button_anim = ButtonAnimation::None;
		Vector2i button_custom_size = { 0, 0 };
		bool button_enabled = true;
		bool button_hovered = false;
		int button_anim_original_x = 0;
		int button_anim_max_x = 0;

	public:
		Button() {};
		Button(std::string button_id, std::string button_texture_path);

		// Returns the button ID
		const std::string id();
		// Set the position of the button
		virtual void set_position(Vector2i pos);
		// Boolean returning true if the mouse is inside the button area
		bool mouse_inside();
		// Set an animation for the button when hovered
		void set_animation(const ButtonAnimation anim);
		// Set a color (added on top)
		void set_color(const SDL_Color color);
		// Enables the button (can be clicked or not.)
		void set_enabled(const bool state);
		// Sets a custom size for the button
		void set_custom_size(const Vector2i size);
		// Returns true or false, if the button is enabled or not
		const bool enabled();
		// Color when hovered
		void set_highlight_color(const SDL_Color color);
		// Color when disabled
		void set_disabled_color(const SDL_Color color);
		std::shared_ptr<Lilac::Texture> texture();
		// Callback when clicked, either static function or lambda
		void set_callback(const std::function<void()> callback);
		// Callback when clicked but not clicked on the button itself - was planned to be used on a text input UI element that got scrapped.
		void set_out_callback(const std::function<void()> callback);
		// Callback when hovered
		void set_hovered_callback(const std::function<void()> callback);
		const Vector2i custom_size();
		virtual void event(const SDL_Event& event);
		virtual void update(const float dt);
		virtual void render();
	};
}