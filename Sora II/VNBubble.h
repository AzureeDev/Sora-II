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

		Vector2i bubble_arrow_orig_pos = {0, 0};
		float bubble_arrow_slide_state = 0.0f;
		float bubble_arrow_slide_speed = 275.f;
		float bubble_arrow_slide_mult = 1.f;

		Image* bubble_arrow_next = nullptr;
		UIText* bubble_name_text = nullptr;
		UIText* bubble_dialog = nullptr;

	public:
		void init();
		const bool visible() const;
		void set_text(const std::string character_name, const std::string dialog);
		void set_visible(const bool state);
		void update(const float dt);

	private:
		void _init_bubble_bg();
		void _init_bubble_name();
		void _init_bubble_dialog();
		void _init_bubble_arrow();
	};
}