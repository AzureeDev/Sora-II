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
	top_bar->set_position({ 0, 32 });

	UIText* top_bar_label = this->create_element<UIText>("mm_top_bar_title", UIText("Main Menu", {255, 255, 255, 255}, 0, Globals::assets->get_font("escom48")));
	top_bar_label->set_position(
		{
			Globals::engine->sdl().workspace_size().x - top_bar_label->text()->data().w - 10,
			top_bar->position().y + (top_bar->texture()->data().h / 2) - top_bar_label->text()->data().h / 2
		}
	);
}

void Lilac::Scenes::MainMenu::init_left_menu()
{
	Image* left_menu_bg = this->create_element<Image>("mm_menu_left_bg", Image("assets/guis/main_menu/main_menu_left"));
	left_menu_bg->set_color(theme_secondary_color);

	UIText* lilac_engine_label = this->create_element<UIText>("mm_lengine_label", UIText("LilacEngine 2 | @Sora#7688"));
	lilac_engine_label->set_position(
		{
			500 / 2 - (lilac_engine_label->text()->data().w / 2),
			Globals::engine->sdl().workspace_size().y - lilac_engine_label->text()->data().h - 10
		}
	);

	Button* exit_btn = this->create_element<Button>("mm_exit_btn", Button("assets/guis/main_menu/exit_button"));
	exit_btn->set_animation(Button::ButtonAnimation::RightSlide);
	exit_btn->set_highlight_color(theme_secondary_color);
	exit_btn->set_position(
		{
			5,
			Globals::engine->sdl().workspace_size().y - lilac_engine_label->text()->data().h - exit_btn->texture()->data().h - 32
		}
	);
	exit_btn->set_callback([]() { Globals::engine->quit(); });
}

void Lilac::Scenes::MainMenu::update(const float dt)
{
}
