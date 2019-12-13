#pragma once
#include "Scene.h"
#include "Image.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	private:
		Lilac::UI::Image texture;

	public:
		virtual void init();
		virtual void update(const float dt);
		virtual void render();
	};
}