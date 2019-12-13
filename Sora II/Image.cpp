#include "Image.h"
#include "Globals.h"

Lilac::UI::Image::Image(std::string path)
{
	this->image_texture = Globals::assets->load_texture("UI::IMAGE_" + path, path);
}

std::shared_ptr<Lilac::Texture> Lilac::UI::Image::texture()
{
	return this->image_texture;
}

void Lilac::UI::Image::render()
{
	SDL_Rect dest_rect = this->image_texture->data().clip_rect;
	dest_rect.x = this->element_position.x;
	dest_rect.y = this->element_position.y;

	dest_rect = Lilac::Utils::Rendering::rescale(dest_rect);
	SDL_RenderCopy(Globals::engine->sdl().get_renderer(), this->image_texture->get(), NULL, &dest_rect);
}
