#include "MainMenu.h"

using Lilac::UI::Image, Lilac::UI::UIText;

void Lilac::Scenes::MainMenu::init()
{
	this->init_world();
	this->init_left_menu();
}

void Lilac::Scenes::MainMenu::init_world()
{
	auto& world = this->create_world("ri_se_sky");
	world.set_world_color({ 0, 160, 230, 255 });
}

void Lilac::Scenes::MainMenu::init_left_menu()
{
	Image* left_menu_bg = this->create_image(Image("assets/guis/main_menu/main_menu_left"));
}

void Lilac::Scenes::MainMenu::update(const float dt)
{

}
