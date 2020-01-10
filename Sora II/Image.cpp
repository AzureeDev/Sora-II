#include "Image.h"
#include "Globals.h"
#include <filesystem>

Lilac::UI::Image::Image(std::string path)
{
	// If pre-loaded, use this instead
	for (auto& image : Globals::assets->all_textures())
	{
		if (image.id == std::filesystem::path(path).filename().generic_u8string())
		{
			this->image_texture = image.texture;
			return;
		}
	}

	this->image_texture = Globals::assets->load_texture("UI::IMAGE_" + path, path);
	this->image_path = path;
	this->element_width = this->image_texture->data().w;
	this->element_height = this->image_texture->data().h;
}

void Lilac::UI::Image::set_texture(std::string path)
{
	for (auto& image : Globals::assets->all_textures())
	{
		if (image.id == "UI::IMAGE_" + path)
		{
			this->image_texture = image.texture;
			return;
		}
	}

	this->image_texture = Globals::assets->load_texture("UI::IMAGE_" + path, path);
	this->image_path = path;
	this->element_width = this->image_texture->data().w;
	this->element_height = this->image_texture->data().h;
}

std::shared_ptr<Lilac::Texture> Lilac::UI::Image::texture()
{
	return this->image_texture;
}

void Lilac::UI::Image::set_color(const SDL_Color color, const Uint8 alpha)
{
	this->image_color.r = color.r;
	this->image_color.g = color.g;
	this->image_color.b = color.b;
	this->image_color.a = alpha;
}

void Lilac::UI::Image::set_alpha(const Uint8 alpha)
{
	this->image_color.a = alpha;
}

void Lilac::UI::Image::set_scroll(const bool state, const TextureScroll scroll_direction, const float speed)
{
	this->scrolling = state;
	this->scroll_state = scroll_direction;
	this->scroll_speed = speed;
}

void Lilac::UI::Image::set_custom_size(const Vector2i size)
{
	this->image_custom_size = size;
	this->element_width = size.x;
	this->element_height = size.y;
}

void Lilac::UI::Image::set_flip(const SDL_RendererFlip flip)
{
	this->image_flip = flip;
}

void Lilac::UI::Image::set_visible(const bool state)
{
	this->image_visible = state;
}

const Vector2i Lilac::UI::Image::custom_size() const
{
	return this->image_custom_size;
}

void Lilac::UI::Image::render()
{
	if (this->image_texture != nullptr)
	{
		if (!this->image_visible)
		{
			return;
		}

		SDL_Rect dest_rect = this->image_texture->data().clip_rect;
		dest_rect.x = this->element_position.x;
		dest_rect.y = this->element_position.y;

		if (!this->image_custom_size.zero())
		{
			dest_rect.w = this->image_custom_size.x;
			dest_rect.h = this->image_custom_size.y;
		}

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);

		this->element_width = dest_rect.w;
		this->element_height = dest_rect.h;

		SDL_SetTextureBlendMode(this->image_texture->get(), SDL_BLENDMODE_BLEND);
		SDL_SetTextureColorMod(this->image_texture->get(), this->image_color.r, this->image_color.g, this->image_color.b);
		SDL_SetTextureAlphaMod(this->image_texture->get(), this->image_color.a);

		if (this->scrolling)
		{
			if (this->scroll_state == TextureScroll::ToLeft)
			{
				this->scroll_offset -= (1 * this->scroll_speed);

				if (this->scroll_offset < -Globals::engine->sdl().workspace_size().x)
				{
					this->scroll_offset = 0;
				}

				const SDL_Rect r_scrollable_texture = { this->scroll_offset, this->position().y, this->element_width, this->element_height };
				const SDL_Rect r_scrollable_texture2 = { this->scroll_offset + Globals::engine->sdl().workspace_size().x, this->position().y, this->element_width, this->element_height };

				SDL_RenderCopyEx(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &r_scrollable_texture, 0, 0, this->image_flip);
				SDL_RenderCopyEx(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &r_scrollable_texture2, 0, 0, this->image_flip);
			}
			else if (this->scroll_state == TextureScroll::ToRight)
			{
				this->scroll_offset += (1 * this->scroll_speed);

				if (this->scroll_offset > Globals::engine->sdl().workspace_size().x)
				{
					this->scroll_offset = 0;
				}

				const SDL_Rect r_scrollable_texture = { this->scroll_offset, this->position().y, this->element_width, this->element_height };
				const SDL_Rect r_scrollable_texture2 = { this->scroll_offset - Globals::engine->sdl().workspace_size().x, this->position().y, this->element_width, this->element_height };

				SDL_RenderCopyEx(Globals::engine->sdl().get_renderer(), this->image_texture->get() , NULL, &r_scrollable_texture, 0, 0, this->image_flip);
				SDL_RenderCopyEx(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &r_scrollable_texture2, 0, 0, this->image_flip);
			}

			return;
		}

		SDL_RenderCopyEx(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &dest_rect, 0, 0, this->image_flip);
	}
}
