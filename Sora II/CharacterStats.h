#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	class CharacterStats : public Scene
	{
	public:
		void init();
		void init_top_bar();
		void init_stat_container();
		void update(const float dt);
	};
}


