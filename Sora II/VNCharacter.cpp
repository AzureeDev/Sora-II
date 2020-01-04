#include "VNScene.h"
#include "Globals.h"

void Lilac::Scenes::VNCharacter::init()
{
	
}

void Lilac::Scenes::VNCharacter::set_flipped(const bool flipped_state)
{
	this->character_flipped = flipped_state;
}

void Lilac::Scenes::VNCharacter::set_active(const bool active_state)
{
	this->character_active = active_state;
}

void Lilac::Scenes::VNCharacter::set_visible(const bool state)
{
	this->character_visible = state;
	this->character_artwork->set_visible(state);
}

Lilac::UI::Image* Lilac::Scenes::VNCharacter::artwork()
{
	return this->character_artwork;
}

void Lilac::Scenes::VNCharacter::create_character(const std::string character_id, const std::string animation)
{
	if (!this->character_artwork_id.empty())
	{
		this->remove_element(this->character_artwork_id);
	}
	
	this->character_id = character_id;
	this->character_name = character_id; // TODO
	this->character_artwork_id = "vn_character_artwork_" + character_id;
	this->character_artwork = this->create_element<Image>("vn_character_artwork_" + character_id, Image("mdls/" + character_id + "_" + animation));
}

void Lilac::Scenes::VNCharacter::say(const std::string text, const std::string animation)
{
	if (!animation.empty())
	{
		this->character_artwork->set_texture("mdls/" + this->character_id + "_" + animation);
	}

	auto vn_scene = Globals::scenes->get_scene<VNScene>("VNScene");
	vn_scene->bubble()->set_text(this->character_name, text);
	vn_scene->bubble()->set_visible(true);
}


void Lilac::Scenes::VNCharacter::update(const float dt)
{
	if (!this->character_active)
	{
		this->character_artwork->set_color({ 150, 150, 150 });
	}
	else
	{
		this->character_artwork->set_color({ 255, 255, 255 });
	}

	this->character_artwork->set_flip(this->character_flipped ? SDL_RendererFlip::SDL_FLIP_HORIZONTAL : SDL_RendererFlip::SDL_FLIP_NONE);
}