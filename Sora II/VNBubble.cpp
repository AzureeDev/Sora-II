#include "VNBubble.h"
#include "Globals.h"

void Lilac::Scenes::VNBubble::init()
{
	this->_init_bubble_bg();
	this->_init_bubble_name();
	this->_init_bubble_dialog();
}

void Lilac::Scenes::VNBubble::set_visible(const bool state)
{
	this->bubble_bg->set_visible(state);
	this->bubble_dialog->set_visible(state);
	this->bubble_name_bg->set_visible(state);
	this->bubble_name_text->set_visible(state);
}

void Lilac::Scenes::VNBubble::update(const float dt)
{
}

void Lilac::Scenes::VNBubble::_init_bubble_bg()
{
	this->bubble_bg = this->create_element<Image>("vn_bubble_bg", Image("guis/novel/vn_bubble"));
	this->bubble_bg->set_color({ 0,0,0 });
	this->bubble_bg->set_position(
		{
			(Globals::engine->sdl().window_size().x / 2) - (this->bubble_bg->width() / 2),
			Globals::engine->sdl().window_size().y - this->bubble_bg->height() - 64
		}
	);

	this->bubble_name_bg = this->create_element<Image>("vn_bubble_name_bg", Image("guis/novel/vn_bubble_name"));
	this->bubble_name_bg->set_color({ 0,0,0 });
	this->bubble_name_bg->set_position(this->bubble_bg->position() - Vector2i(0, this->bubble_name_bg->height() + 3));
}

void Lilac::Scenes::VNBubble::_init_bubble_name()
{
	this->bubble_name_text = this->create_element<UIText>("vn_bubble_name_text", UIText("Sora", { 255, 255, 255, 255 }, 0, Globals::assets->get_font("escom32")));
	this->bubble_name_text->set_position(this->bubble_name_bg->position() + Vector2i(10, (this->bubble_name_bg->height() / 2) - this->bubble_name_text->height() / 2));
}

void Lilac::Scenes::VNBubble::_init_bubble_dialog()
{
	this->bubble_dialog = this->create_element<UIText>("vn_bubble_dialog", UIText("Hum. We should probably go back home... don't you think?", { 230, 230, 230, 255 }, this->bubble_bg->width() - 40, Globals::assets->get_font("infini38")));
	this->bubble_dialog->set_position(this->bubble_bg->position() + Vector2i(20, 20));
}
