#pragma once
#include <memory>
#include "UIElement.h"
#include "Text.h"

namespace Lilac::UI
{
	class UIText : public Lilac::UI::UIElement
	{
	private:
		std::shared_ptr<Lilac::Text> text_obj = nullptr;
		bool uitext_visible = true;

	public:
		UIText() {};
		// Create a new text. max_width is used to define a maximum width value before going to a new line directly. 0 means "workspace width" that doesn't take the current position in consideration.
		UIText(std::string text, SDL_Color color = { 255, 255, 255, 255 }, int max_width = 0, std::shared_ptr<Lilac::Font> font = nullptr);
		std::shared_ptr<Lilac::Text> text() { return this->text_obj; };
		void set_text(const std::string text); // Sets the current Text object to a new text. Automatically destroys the previous text
		void set_color(const SDL_Color color); // Set the text color
		void set_visible(const bool visible); // Set the text visibility
		const Vector2i top();
		const Vector2i bottom();
		const Vector2i right();
		const Vector2i left();
		void render();
	};
}