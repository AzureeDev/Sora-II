#include "SceneManager.h"
#include <SDL_log.h>

void Lilac::SceneManager::create_scene(const SceneData data)
{
	if (this->exists(data.scene_name))
	{
		SDL_Log("Lilac::SceneManager::create_scene : A scene with the name %s already exists", data.scene_name.c_str());
		return;
	}

	this->active_scenes.push_back(data);

	data.scene->init();
}

bool Lilac::SceneManager::exists(const std::string scene_name)
{
	for (auto& scene : this->active_scenes)
	{
		if (scene.scene_name == scene_name)
		{
			return true;
		}
	}

	return false;
}

std::shared_ptr<Lilac::Scene> Lilac::SceneManager::get_scene(const std::string scene_name)
{
	for (auto& scene : this->active_scenes)
	{
		if (scene.scene_name == scene_name)
		{
			return scene.scene;
		}
	}

	return nullptr;
}

void Lilac::SceneManager::update(const float dt)
{
	for (const auto& scene : this->active_scenes)
	{
		scene.scene->update(dt);
	}
}
