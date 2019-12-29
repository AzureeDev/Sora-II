#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	using Lilac::UI::Image;

	class VNBubble : public Scene
	{
	private:
		Image* bubble_bg = nullptr;

	public:
		void init();
		void update(const float dt);

	private:
		void _init_bubble_bg();
	};
}