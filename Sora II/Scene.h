#pragma once

/* Include base libraries for scenes */
#include <SDL.h>
#include <memory>
#include <vector>
#include <string>
#include "World.h"
#include "Image.h"
#include "UIText.h"
#include "Button.h"

namespace Lilac {
	class Scene
	{
	public:
		struct UIElementDefinition {
			std::string identifier;
			int layer = 1;
			std::shared_ptr<Lilac::UI::UIElement> ui_element = nullptr;
		};

	protected:
		bool scene_paused = false;						// When paused, the scene stops updating the logic
		float scene_timer = 0.0f;						// Time passed since the scene was created. This timer is not updated if the scene is paused
		std::vector<UIElementDefinition> scene_ui_elements = {};
		World scene_world;

	public:
		virtual ~Scene();								// Destructor, put cleanups here
		virtual void init();							// Executed on scene creation
		virtual void event(SDL_Event& event);			// Event catcher
		void _private_update(const float dt);			// Private update, do not use - Scene timer is handled here.
		virtual void update(const float dt);			// Executed each frames, put logic in there
		virtual void render();							// Executed each frames AFTER logic
		const bool paused() const { return this->scene_paused; }	// Boolean if the scene logic is paused
		void pause() { this->scene_paused = true; }		// Setter for the pause
		void resume() { this->scene_paused = false; }	// Setter to unpause

	protected:
		Lilac::World& create_world(const std::string world_identifier);

		template<typename T>
		T* create_element(const std::string id, const T element, const int layer = 1);
		template<typename T>
		T* get_element(const std::string id);
		void set_element_layer(const std::string id, const int layer);
		void remove_element(const std::string id);
		void clear_all_elements();

	private:
		void trigger_layer_sorting();

	};

	template<typename T>
	inline T* Scene::create_element(const std::string id, const T element, const int layer)
	{
		this->scene_ui_elements.push_back({ id, layer, std::make_shared<T>(element) });
		this->trigger_layer_sorting();

		return dynamic_cast<T*>(this->scene_ui_elements.back().ui_element.get());
	}

	template<typename T>
	inline T* Scene::get_element(const std::string id)
	{
		for (auto& element : this->scene_ui_elements)
		{
			if (element.identifier == id)
			{
				return dynamic_cast<T*>(element.ui_element.get());
			}
		}

		SDL_Log("Scene::get_element : Element %s not found...", id.c_str());
		return nullptr;
	}
}