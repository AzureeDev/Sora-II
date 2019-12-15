#pragma once
#include "Scene.h"
#include "Unit.h"
#include "UIText.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	private:
		Lilac::Units::Unit unit;
		Lilac::UI::UIText text;

	public:
		virtual void init();
		virtual void update(const float dt);
		virtual void render();
	};
}