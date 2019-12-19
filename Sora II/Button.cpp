#include "Button.h"
#include "Globals.h"

Lilac::UI::Button::Button(std::string button_texture_path)
{
	this->button_texture = Globals::assets->load_texture("UI::BUTTON_" + button_texture_path, button_texture_path);
	this->button_callback = [button_texture_path]() { SDL_Log("No valid callback for the button: %s", button_texture_path.c_str()); };
}

bool Lilac::UI::Button::mouse_inside()
{
	bool inside = true;

	if (Globals::mousePositionX < this->element_position.x)
	{
		inside = false;
	}
	else if (Globals::mousePositionX > this->element_position.x + this->button_texture->data().w)
	{
		inside = false;
	}
	else if (Globals::mousePositionY < this->element_position.y)
	{
		inside = false;
	}
	else if (Globals::mousePositionY > this->element_position.y + this->button_texture->data().h)
	{
		inside = false;
	}

	return inside;
}

void Lilac::UI::Button::set_color(const SDL_Color color)
{
	this->button_color.r = color.r;
	this->button_color.g = color.g;
	this->button_color.b = color.b;
}

std::shared_ptr<Lilac::Texture> Lilac::UI::Button::texture()
{
	return this->button_texture;
}

void Lilac::UI::Button::set_callback(std::function<void()> callback)
{
	this->button_callback = callback;
}

void Lilac::UI::Button::event(const SDL_Event& event)
{
	if (event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT && this->mouse_inside())
		{
			this->button_callback();
		}
	}
}

void Lilac::UI::Button::render()
{
	if (this->button_texture != nullptr)
	{
		SDL_Rect dest_rect = this->button_texture->data().clip_rect;
		dest_rect.x = this->element_position.x;
		dest_rect.y = this->element_position.y;

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);

		SDL_SetTextureColorMod(this->button_texture->get(), this->button_color.r, this->button_color.g, this->button_color.b);
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->button_texture->get(), NULL, &dest_rect);
	}
}
