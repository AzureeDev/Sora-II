#include "Button.h"
#include "Globals.h"

Lilac::UI::Button::Button(std::string button_texture_path)
{
	this->button_texture = Globals::assets->load_texture("UI::BUTTON_" + button_texture_path, button_texture_path);
}

void Lilac::UI::Button::render()
{
	if (this->button_texture != nullptr)
	{
		SDL_Rect dest_rect = this->button_texture->data().clip_rect;
		dest_rect.x = this->element_position.x;
		dest_rect.y = this->element_position.y;

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->button_texture->get(), NULL, &dest_rect);
	}
}
