#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	using Lilac::UI::Image, Lilac::UI::UIText;

	class VNBubble : public Scene
	{
	private:
		bool bubble_visible = true;
		Image* bubble_bg = nullptr;
		Image* bubble_name_bg = nullptr;
		Image* bubble_arrow_next = nullptr;
		UIText* bubble_name_text = nullptr;
		UIText* bubble_dialog = nullptr;

	public:
		void init();
		void set_visible(const bool state);
		void update(const float dt);

	private:
		void _init_bubble_bg();
		void _init_bubble_name();
		void _init_bubble_dialog();
		void _init_bubble_arrow();
	};
}