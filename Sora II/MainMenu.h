#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	class MainMenu : public Scene
	{
	public:
		void init();
		void init_left_menu();
		void update(const float dt);
	};
}