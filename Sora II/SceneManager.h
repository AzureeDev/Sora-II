#pragma once
#include <memory>
#include <string>
#include "Scene.h"

namespace Lilac
{
	struct SceneData {
		std::string scene_name;
		std::shared_ptr<Scene> scene = nullptr;
	};

	class SceneManager
	{
	private:
		std::vector<SceneData> active_scenes = {};

	public:
		void create_scene(const SceneData data);
		bool exists(const std::string scene_name);
		std::shared_ptr<Lilac::Scene> get_scene(const std::string scene_name);
		void update(const float dt);
	};
}