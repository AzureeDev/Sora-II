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

	public:
		UIText() {};
		UIText(std::string text, SDL_Color color = { 255, 255, 255, 255 }, int max_width = 0, std::shared_ptr<Lilac::Font> font = nullptr);
		std::shared_ptr<Lilac::Text> text() { return this->text_obj; };
		void render();
	};
}