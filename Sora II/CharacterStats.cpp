#include "CharacterStats.h"
#include "Globals.h"

using namespace Lilac::UI;

void Lilac::Scenes::CharacterStats::init()
{
	MusicManager::play_with_repeat("musics/suguri3", 118.519);
	Globals::engine->set_cursor_state(true);

	Image* scene_bg = this->create_element<Image>("scene_bg", Image("guis/main_menu/character_stats_bg"));
	Image* character_art = this->create_element<Image>("character_art", Image("units/sora_m/_art"));
	character_art->set_position(
		{
			0,
			Globals::engine->sdl().workspace_size().y - character_art->texture()->data().h
		}
	);

	this->init_top_bar();
	this->init_stat_container();
}

void Lilac::Scenes::CharacterStats::init_top_bar()
{
	Image* top_bar_bg = this->create_element<Image>("top_bar_bg", Image("guis/rect_base"));
	top_bar_bg->set_color({ 0, 0, 0 }, 175);
	top_bar_bg->set_custom_size({ Globals::engine->sdl().workspace_size().x, 64 });
	top_bar_bg->set_position({ 0, 32 });

	UIText* top_bar_text = this->create_element<UIText>("top_bar_text", UIText("Statistics of Sora", { 255,255,255,255 }, 0, Globals::assets->get_font("escom48_italic")));
	top_bar_text->set_position(
		{
			16,
			top_bar_bg->position().y + (top_bar_bg->custom_size().y / 2) - top_bar_text->text()->data().h / 2
		}
	);
}

void Lilac::Scenes::CharacterStats::init_stat_container()
{
	/*
	Image* stat_container = this->create_element<Image>("stat_container", Image("guis/rect_base"));
	stat_container->set_custom_size({ 1000, 400 });
	stat_container->set_color({ 0,0,0 }, 175);
	stat_container->set_position((this->get_element<Image>("character_art")->right() - Vector2i(128, 0)) + Vector2i(0, 64));*/

	UIText* outlined_txt = this->create_element<UIText>("outlined_txt", UIText("Sora (Military)", { 255,255,255,255 }));
	outlined_txt->set_position(this->get_element<Image>("character_art")->right() + Vector2i(-128, 64));
}

void Lilac::Scenes::CharacterStats::update(const float dt)
{
}
