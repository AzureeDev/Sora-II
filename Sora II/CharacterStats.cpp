#include "CharacterStats.h"
#include "Globals.h"

using namespace Lilac::UI;

void Lilac::Scenes::CharacterStats::init()
{
	this->create_world("ri_se_sky");
	this->scene_world.set_world_color({ 100, 160, 255, 175 });
	MusicManager::play_with_repeat("musics/suguv3", 118.418);
	Globals::engine->set_cursor_state(true);

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
	Image* top_bar_bg = this->create_element<Image>("top_bar_bg", Image("guis/main_menu/main_menu_top_bar"));
	top_bar_bg->set_color({ 75, 135, 255 });
	top_bar_bg->set_position({ 0, 32 });
	top_bar_bg->set_scroll(true);

	UIText* top_bar_text = this->create_element<UIText>("top_bar_text", UIText("Statistics", { 255,255,255,255 }, 0, Globals::assets->get_font("escom48_italic")));
	top_bar_text->set_position(
		{
			16,
			top_bar_bg->position().y + (top_bar_bg->height() / 2) - top_bar_text->height() / 2
		}
	);
}

void Lilac::Scenes::CharacterStats::init_stat_container()
{
	/*
		Character name
	*/

	Image* character_name_bg = this->create_element<Image>("character_name_bg", Image("guis/rect_base"), -1);
	character_name_bg->set_custom_size({ Globals::engine->sdl().workspace_size().x, 92 });
	character_name_bg->set_color({ 0, 0, 0 }, 225);
	character_name_bg->set_position(this->get_element<Image>("top_bar_bg")->bottom());

	UIText* character_name = this->create_element<UIText>("character_name", UIText("Sora (Military)", { 255,255,255,255 }, 0, Globals::assets->get_font("escom48")));
	character_name->set_position(
		{
			this->get_element<Image>("character_art")->right().x - 128,
			character_name_bg->position().y + (character_name_bg->height() / 2) - character_name->height() / 2
		}
	);

	/*
		Background workspace
	*/

	Image* character_ws_bg = this->create_element<Image>("character_ws_bg", Image("guis/rect_base"), -1);
	character_ws_bg->set_custom_size({ Globals::engine->sdl().workspace_size().x, Globals::engine->sdl().window_size().y });
	character_ws_bg->set_color({ 0, 0, 0 }, 190);
	character_ws_bg->set_position(character_name_bg->bottom());

	/*
		Description of the character
	*/

	UIText* character_description = this->create_element<UIText>("character_desc", UIText(
		"Sora, in her Military variant, is more focused on combat and the ability to pursue other units, in order to bring them down. She won't have any recovery rolls, but she cannot use powerful skills.",
		{ 235, 235, 235, 255 },
		980,
		Globals::assets->get_font("infini24")
	));
	character_description->set_position(
		{
			character_name->left().x,
			character_name_bg->bottom().y + 64
		}
	);

	/*
		Background stats
	*/

	Image* character_stats_bg = this->create_element<Image>("character_stats_bg", Image("guis/rect_base"));
	character_stats_bg->set_custom_size({ 950, 200 });
	character_stats_bg->set_color({ 0, 0, 0 }, 160);
	character_stats_bg->set_position(
		{
			character_description->left().x,
			character_description->bottom().y + 32
		}
	);

	/*
		Stats rendering
	*/

	struct Statistics {
		std::string name;
		int amount;
	};

	const std::vector<Statistics> character_stats = {
		{ "Attack", 65 },
		{ "Defense", 25 },
		{ "Evasion", 45 },
		{ "Recovery", 100 }
	};

	for (size_t i = 0; i < character_stats.size(); ++i)
	{
		UIText* statistic_label = nullptr;
		UIText* statistic_amount = nullptr;

		statistic_label = this->create_element<UIText>("character_stat_" + std::to_string(i), UIText(character_stats[i].name));
		statistic_amount = this->create_element<UIText>("character_stat_amount_" + std::to_string(i), UIText(std::to_string(character_stats[i].amount)));

		if (i == 0)
		{
			statistic_label->set_position(character_stats_bg->position() + Vector2i(16, 16));
			statistic_amount->set_position(statistic_label->position() + Vector2i(128 * 3, 0));
		}
		else
		{
			Vector2i previous_item_label_bottom = this->get_element<UIText>("character_stat_" + std::to_string(i - 1))->bottom();
			Vector2i previous_item_amount_bottom = this->get_element<UIText>("character_stat_amount_" + std::to_string(i - 1))->bottom();

			statistic_label->set_position(previous_item_label_bottom + Vector2i(0, 16));
			statistic_amount->set_position(previous_item_amount_bottom + Vector2i(0, 16));
		}
	}
}

void Lilac::Scenes::CharacterStats::update(const float dt)
{
}