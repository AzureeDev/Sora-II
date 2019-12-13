#pragma once
#include "Scene.h"
#include "Unit.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	private:
		Lilac::Units::Unit unit;

	public:
		virtual void init();
		virtual void update(const float dt);
		virtual void render();
	};
}