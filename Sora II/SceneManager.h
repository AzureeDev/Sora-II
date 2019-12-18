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
		// SceneData: { string: scene_name, shared_ptr: scene }
		void create_scene(const SceneData data);			// Create a new scene
		void delete_scene(const std::string scene_name);	// Delete a existing scene and removes it from the container
		// SceneData: { string: scene_name, shared_ptr: scene }
		void swap_scene(const std::string scene_name_to_delete, SceneData new_scene_data); // Combine create & delete scene in one function
		bool exists(const std::string scene_name);			// Boolean if a scene exists or not by scene name
		template <typename T>
		std::shared_ptr<T> get_scene(const std::string scene_name);	// Get a scene. Eg: Globals::scenes->get_scene<GameInit>("GameInit")->function()
		void update(const float dt);	// Update, for the main loop
		void render();	// Render, for the main loop
	};

	/* The fact I use a template here is to have polymorphism even though it's a container of basic scenes - We can get all functions from a designated class with this. */
	template<typename T>
	inline std::shared_ptr<T> SceneManager::get_scene(const std::string scene_name)
	{
		for (auto& scene : this->active_scenes)
		{
			if (scene.scene_name == scene_name)
			{
				return scene.scene;
			}
		}
	}
}