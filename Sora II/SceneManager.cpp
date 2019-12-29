#include "SceneManager.h"
#include <SDL_log.h>

void Lilac::SceneManager::create_scene(const SceneData data)
{
	if (this->exists(data.scene_name))
	{
		SDL_Log("Lilac::SceneManager::create_scene : A scene with the name %s already exists", data.scene_name.c_str());
		return;
	}

	SDL_Log("SceneManager: Created Scene %s", data.scene_name.c_str());
	this->active_scenes.push_back(data);

	data.scene->_set_scene_name(data.scene_name);
	data.scene->init();
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

void Lilac::SceneManager::swap_scene(const std::string scene_name_to_delete, SceneData new_scene_data)
{
	this->create_scene(new_scene_data);
	this->delete_scene(scene_name_to_delete);
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

void Lilac::SceneManager::event(SDL_Event& event)
{
	for (const auto& scene : this->active_scenes)
	{
		if (!scene.scene->paused())
		{
			scene.scene->event(event);
		}
	}
}

void Lilac::SceneManager::update(const float dt)
{
	for (const auto& scene : this->active_scenes)
	{
		if (!scene.scene->paused())
		{
			scene.scene->_private_update(dt);
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
