#include "Button.h"
#include "Globals.h"

Lilac::UI::Button::Button(std::string button_id, std::string button_texture_path)
{
	this->button_id = button_id;
	this->button_texture = Globals::assets->load_texture("UI::BUTTON_" + button_texture_path, button_texture_path);
	this->button_callback = [button_texture_path]() { SDL_Log("No valid callback for the button: %s", button_texture_path.c_str()); };
	this->button_out_callback = []() {};
}

const std::string Lilac::UI::Button::id()
{
	return this->button_id;
}

void Lilac::UI::Button::set_position(Vector2i pos)
{
	this->element_position = pos;

	this->button_anim_original_x = pos.x;
	this->button_anim_max_x = pos.x + 20;
}

bool Lilac::UI::Button::mouse_inside()
{
	bool inside = true;

	int w = this->button_texture->data().w;
	int h = this->button_texture->data().h;

	if (!this->button_custom_size.zero())
	{
		w = this->button_custom_size.x;
		h = this->button_custom_size.y;
	}

	if (Globals::mousePositionX < this->element_position.x)
	{
		inside = false;
	}
	else if (Globals::mousePositionX > this->element_position.x + w)
	{
		inside = false;
	}
	else if (Globals::mousePositionY < this->element_position.y)
	{
		inside = false;
	}
	else if (Globals::mousePositionY > this->element_position.y + h)
	{
		inside = false;
	}

	return inside;
}

void Lilac::UI::Button::set_animation(const ButtonAnimation anim)
{
	this->button_anim = anim;
}

void Lilac::UI::Button::set_color(const SDL_Color color)
{
	this->button_color.r = color.r;
	this->button_color.g = color.g;
	this->button_color.b = color.b;
}

void Lilac::UI::Button::set_enabled(const bool state)
{
	this->button_enabled = state;
}

void Lilac::UI::Button::set_custom_size(const Vector2i size)
{
	this->button_custom_size = size;
}

const bool Lilac::UI::Button::enabled()
{
	return this->button_enabled;
}

void Lilac::UI::Button::set_highlight_color(const SDL_Color color)
{
	this->button_highlight_color.r = color.r;
	this->button_highlight_color.g = color.g;
	this->button_highlight_color.b = color.b;
}

void Lilac::UI::Button::set_disabled_color(const SDL_Color color)
{
	this->button_disabled_color.r = color.r;
	this->button_disabled_color.g = color.g;
	this->button_disabled_color.b = color.b;
}

std::shared_ptr<Lilac::Texture> Lilac::UI::Button::texture()
{
	return this->button_texture;
}

void Lilac::UI::Button::set_callback(const std::function<void()> callback)
{
	this->button_callback = callback;
}

void Lilac::UI::Button::set_out_callback(const std::function<void()> callback)
{
	this->button_out_callback = callback;
}

void Lilac::UI::Button::set_hovered_callback(const std::function<void()> callback)
{
	this->button_on_hover_callback = callback;
}

const Vector2i Lilac::UI::Button::custom_size()
{
	return this->button_custom_size;
}

void Lilac::UI::Button::event(const SDL_Event& event)
{
	if (!this->enabled())
	{
		return;
	}

	if (event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT && this->mouse_inside())
		{
			this->button_callback();
		}
		else
		{
			this->button_out_callback();
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

		if (!this->button_custom_size.zero())
		{
			dest_rect.w = this->button_custom_size.x;
			dest_rect.h = this->button_custom_size.y;
		}

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);

		SDL_SetTextureBlendMode(this->button_texture->get(), SDL_BlendMode::SDL_BLENDMODE_BLEND);
		SDL_SetTextureColorMod(this->button_texture->get(), this->button_color.r, this->button_color.g, this->button_color.b);
		SDL_SetTextureAlphaMod(this->button_texture->get(), this->button_color.a);

		if (this->mouse_inside())
		{
			SDL_SetTextureColorMod(this->button_texture->get(), this->button_highlight_color.r, this->button_highlight_color.g, this->button_highlight_color.b);
			SDL_SetTextureAlphaMod(this->button_texture->get(), this->button_highlight_color.a);

			if (!this->button_hovered)
			{
				this->button_on_hover_callback();
				this->button_hovered = true;
			}
		}
		else
		{
			this->button_hovered = false;
		}

		if (!this->enabled())
		{
			SDL_SetTextureColorMod(this->button_texture->get(), this->button_disabled_color.r, this->button_disabled_color.g, this->button_disabled_color.b);
			SDL_SetTextureAlphaMod(this->button_texture->get(), this->button_disabled_color.a);
		}

		if (this->button_anim == ButtonAnimation::RightSlide && this->enabled())
		{
			if (this->mouse_inside())
			{
				if (this->position().x < this->button_anim_max_x)
				{
					this->set_x(this->position().x + 2);
				}
			}
			else
			{
				if (this->position().x > this->button_anim_original_x)
				{
					this->set_x(this->position().x - 2);
				}
			}
		}
		
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->button_texture->get(), NULL, &dest_rect);
	}
}
