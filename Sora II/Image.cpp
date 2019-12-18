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
}

std::shared_ptr<Lilac::Texture> Lilac::UI::Image::texture()
{
	return this->image_texture;
}

void Lilac::UI::Image::render()
{
	if (this->image_texture != nullptr)
	{
		SDL_Rect dest_rect = this->image_texture->data().clip_rect;
		dest_rect.x = this->element_position.x;
		dest_rect.y = this->element_position.y;

		dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);
		SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &dest_rect);
	}
}
