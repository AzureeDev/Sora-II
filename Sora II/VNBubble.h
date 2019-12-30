#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	using Lilac::UI::Image, Lilac::UI::UIText;

	class VNBubble : public Scene
	{
	private:
		Image* bubble_bg = nullptr;
		Image* bubble_name_bg = nullptr;
		UIText* bubble_name_text = nullptr;
		UIText* bubble_dialog = nullptr;

	public:
		void init();
		void update(const float dt);

	private:
		void _init_bubble_bg();
		void _init_bubble_name();
		void _init_bubble_dialog();
	};
}