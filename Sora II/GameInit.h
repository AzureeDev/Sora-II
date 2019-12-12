#pragma once
#include "Scene.h"
#include "Image.h"

namespace Lilac::Scenes
{
	class GameInit : public Lilac::Scene
	{
	private:
		std::vector<std::unique_ptr<Lilac::UI::Image>> textures = {};

	public:
		virtual void init();
		virtual void update(const float dt);
	};
}