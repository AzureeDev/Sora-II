#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	public:
		virtual void init();
		virtual void update(const float dt);
	};
}