#pragma once
#include "Scene.h"

using Lilac::UI::Image, Lilac::UI::UIText, Lilac::UI::Button;

namespace Lilac::Scenes
{
	class MainMenu : public Scene
	{
	private:
		std::vector<Button*> left_menu_btns = {};

	public:
		void init();
		void init_world();
		void init_top_bar();
		void init_menu_bar();
		void init_left_menu();
		void clear_left_menu_buttons();
		void update(const float dt);
	};
}