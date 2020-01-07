#include "UIText.h"
#include "Globals.h"

Lilac::UI::UIText::UIText(std::string text, SDL_Color color, int max_width, std::shared_ptr<Lilac::Font> font)
{
	this->text_obj = std::shared_ptr<Lilac::Text>(new Lilac::Text(text, color, max_width, font));

	this->element_width = this->text_obj->data().w;
	this->element_height = this->text_obj->data().h;
}

void Lilac::UI::UIText::set_text(const std::string text)
{
	this->text_obj->set_text(text);
	this->element_width = this->text_obj->data().w;
	this->element_height = this->text_obj->data().h;
}

void Lilac::UI::UIText::set_color(const SDL_Color color)
{
	this->text_obj->set_color(color);
}

void Lilac::UI::UIText::set_visible(const bool visible)
{
	this->uitext_visible = visible;
}

const Vector2i Lilac::UI::UIText::top()
{
	return this->element_position;
}

const Vector2i Lilac::UI::UIText::bottom()
{
	return this->element_position + Vector2i(0, this->element_height);
}

const Vector2i Lilac::UI::UIText::right()
{
	return this->element_position + Vector2i(this->element_width, 0);
}

const Vector2i Lilac::UI::UIText::left()
{
	return this->element_position;
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
