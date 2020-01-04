#include "Globals.h"
#include "VNManager.h"

void Lilac::VNManager::init()
{
	this->bubble = Globals::scenes->get_scene<Lilac::Scenes::VNBubble>("VNBubble");
	this->scene = Globals::scenes->get_scene<Lilac::Scenes::VNScene>("VNScene");
	this->l_unit = Globals::scenes->get_scene<Lilac::Scenes::VNCharacter>("l_unit");
	this->r_unit = Globals::scenes->get_scene<Lilac::Scenes::VNCharacter>("r_unit");
}

void Lilac::VNManager::read_next_dialog()
{
	if (this->current_dialog_id == 0)
	{
		this->current_dialog_id = 1;
	}
	else
	{
		this->current_dialog_id++;
	}

	this->current_dialog_element = this->chapter_reader.get_dialog_by_id(this->current_dialog_id);

	this->_set_new_actor();
}

void Lilac::VNManager::update(const float dt)
{
}

void Lilac::VNManager::_set_new_actor()
{

}
