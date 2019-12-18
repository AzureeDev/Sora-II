#include "GameInit.h"
#include "Globals.h"
#include "MainMenu.h"

using Lilac::UI::UIText;

void Lilac::Scenes::GameInit::init()
{
	UIText* loading_label = this->create_text(UIText("Loading...", { 135, 135, 135, 255 }));
	loading_label->set_position(
		{
			Globals::engine->sdl().workspace_size().x - loading_label->text()->data().w - 10,
			Globals::engine->sdl().workspace_size().y - loading_label->text()->data().h - 10
		}
	);

	Globals::assets->load_texture("main_menu_left", "assets/guis/main_menu/main_menu_left");

	this->destroy_scene();
}

void Lilac::Scenes::GameInit::update(const float dt)
{
}

void Lilac::Scenes::GameInit::destroy_scene()
{
	Globals::scenes->swap_scene("GameInit", { "MainMenu", std::shared_ptr<Lilac::Scenes::MainMenu>(new Lilac::Scenes::MainMenu()) });
}