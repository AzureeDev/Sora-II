#include "SceneManager.h"
#include <SDL_log.h>

void Lilac::SceneManager::create_scene(const SceneData data)
{
	if (this->exists(data.scene_name))
	{
		SDL_Log("Lilac::SceneManager::create_scene : A scene with the name %s already exists", data.scene_name.c_str());
		return;
	}

	data.scene->init();
	this->active_scenes.push_back(data);
}

void Lilac::SceneManager::delete_scene(const std::string scene_name)
{
	for (size_t i = 0; i < this->active_scenes.size(); ++i)
	{
		if (this->active_scenes[i].scene_name == scene_name)
		{
			this->active_scenes.erase(this->active_scenes.begin() + i);
			break;
		}
	}
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

void Lilac::SceneManager::update(const float dt)
{
	for (const auto& scene : this->active_scenes)
	{
		if (!scene.scene->paused())
		{
			scene.scene->update(dt);
		}
	}
}

void Lilac::SceneManager::render()
{
	for (const auto& scene : this->active_scenes)
	{
		scene.scene->render();
	}
}
