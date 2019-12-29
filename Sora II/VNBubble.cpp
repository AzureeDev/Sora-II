#include "VNBubble.h"
#include "Globals.h"

void Lilac::Scenes::VNBubble::init()
{
	this->_init_bubble_bg();
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
}
