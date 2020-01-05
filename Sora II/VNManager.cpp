#include "Globals.h"
#include "VNManager.h"

void Lilac::VNManager::init()
{
	this->bubble = Globals::scenes->get_scene<Lilac::Scenes::VNBubble>("VNBubble");
	this->scene = Globals::scenes->get_scene<Lilac::Scenes::VNScene>("VNScene");
	this->l_unit = Globals::scenes->get_scene<Lilac::Scenes::VNCharacter>("l_unit");
	this->r_unit = Globals::scenes->get_scene<Lilac::Scenes::VNCharacter>("r_unit");

	this->_pre_init_chapter();
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

	// Set actors inactive here - we set one in _set_new_actor()
	this->l_unit->set_active(false);
	this->r_unit->set_active(false);

	// Init the dialog and events by the parameters in the XML
	this->current_dialog_element = this->chapter_reader.get_dialog_by_id(this->current_dialog_id);
	this->_set_new_actor();
}

void Lilac::VNManager::update(const float dt)
{
}

void Lilac::VNManager::_pre_init_chapter()
{
	const auto initial_l_unit = this->chapter_reader.get_initial_l_unit_id();
	const auto initial_r_unit = this->chapter_reader.get_initial_r_unit_id();

	// Set initial characters
	this->l_unit->create_character(initial_l_unit);
	this->r_unit->create_character(initial_r_unit);
}

void Lilac::VNManager::_set_new_actor()
{
	const auto element = this->current_dialog_element;
	const auto current_l_actor = this->l_unit->id();
	const auto current_r_actor = this->r_unit->id();

	// Params
	const auto actor = element->Attribute("side") == "right" ? this->r_unit : this->l_unit;
	const auto need_flip = element->Attribute("flip") == "true" ? true : false;
	const auto need_hide = element->Attribute("hide") == "true" ? false : true;

	actor->set_active(true);
	actor->set_flipped(need_flip);
	actor->set_visible(need_hide);
}
