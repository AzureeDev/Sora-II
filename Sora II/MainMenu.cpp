#include "MainMenu.h"
#include "Globals.h"

using Lilac::UI::Image, Lilac::UI::UIText, Lilac::UI::Button;

// base theme: { 0, 155, 255, 255 }
// christmas theme: { 0, 155, 255, 255 } / { 255, 165, 165, 255 }

const SDL_Color theme_primary_color = { 0, 155, 255, 255 };
const SDL_Color theme_secondary_color = { 0, 155, 255, 255 };

void Lilac::Scenes::MainMenu::init()
{
	this->init_world();
	this->init_top_bar();
	this->init_menu_bar();
	this->init_left_menu();
}

void Lilac::Scenes::MainMenu::init_world()
{
	auto& world = this->create_world("ri_se_sky");
	world.set_world_color(theme_primary_color);
}

void Lilac::Scenes::MainMenu::init_top_bar()
{
	Image* top_bar = this->create_element<Image>("mm_top_bar", Image("assets/guis/main_menu/main_menu_top_bar"));
	top_bar->set_scroll(true);
	top_bar->set_color(theme_secondary_color);

	UIText* top_bar_label = this->create_element<UIText>("mm_top_bar_title", UIText("Main Menu", {255, 255, 255, 255}, 0, Globals::assets->get_font("escom48")));
	top_bar_label->set_position(
		{
			Globals::engine->sdl().workspace_size().x - top_bar_label->text()->data().w - 10,
			top_bar->position().y + (top_bar->texture()->data().h / 2) - top_bar_label->text()->data().h / 2
		}
	);
}

void Lilac::Scenes::MainMenu::init_menu_bar()
{
	auto top_bar = this->get_element<Image>("mm_top_bar");

	Image* menu_bar_bg = this->create_element<Image>("mm_menu_bar_bg", Image("assets/guis/rect_base"));
	menu_bar_bg->set_custom_size({ Globals::engine->sdl().workspace_size().x, 64 });
	menu_bar_bg->set_color({ 0, 0, 0 }, 150);
	menu_bar_bg->set_position({ 0, top_bar->position().y + top_bar->texture()->data().h });
}

void Lilac::Scenes::MainMenu::init_left_menu()
{

}

void Lilac::Scenes::MainMenu::update(const float dt)
{
}
