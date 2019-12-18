#pragma once
#include "Scene.h"
#include "Unit.h"
#include "UIText.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	public:
		virtual void init();
		virtual void update(const float dt);

	private:
		void destroy_scene();
	};
}