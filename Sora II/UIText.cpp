#include "UIText.h"
#include "Globals.h"

Lilac::UI::UIText::UIText(std::string text, SDL_Color color, int max_width, std::shared_ptr<Lilac::Font> font)
{
	this->text_obj = std::shared_ptr<Lilac::Text>(new Lilac::Text(text, color, max_width, font));
}

void Lilac::UI::UIText::set_visible(const bool visible)
{
	this->uitext_visible = visible;
}

void Lilac::UI::UIText::render()
{
	if (!this->uitext_visible)
	{
		return;
	}

	if (this->text_obj != nullptr)
	{
		SDL_Rect dest_rect = this->text_obj->data().clip_rect;
		dest_rect.x = this->element_position.x;
		dest_rect.y = this->element_position.y;

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->text_obj->get(), NULL, &dest_rect);
	}
}
