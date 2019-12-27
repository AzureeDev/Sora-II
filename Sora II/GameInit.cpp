#include "GameInit.h"
#include "Globals.h"
#include "CharacterStats.h"

using Lilac::UI::UIText;

void Lilac::Scenes::GameInit::init()
{
	Globals::engine->init_base_assets();
	this->destroy_scene();
}

void Lilac::Scenes::GameInit::update(const float dt)
{
}

void Lilac::Scenes::GameInit::destroy_scene()
{
	Globals::scenes->swap_scene("GameInit", { "CharacterStats", std::shared_ptr<Lilac::Scenes::CharacterStats>(new Lilac::Scenes::CharacterStats()) });
}