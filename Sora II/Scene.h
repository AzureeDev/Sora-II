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
	protected:
		bool scene_paused = false;						// When paused, the scene stops updating the logic
		std::vector<std::shared_ptr<Lilac::UI::UIElement>> scene_ui_elements = {};
		World scene_world;

	public:
		virtual ~Scene();								// Destructor, put cleanups here
		virtual void init();							// Executed on scene creation
		virtual void event(SDL_Event& event);			// Event catcher
		virtual void update(const float dt);			// Executed each frames, put logic in there, as well of inserting elements
		virtual void render();							// Executed each frames AFTER logic
		bool paused() { return this->scene_paused; }	// Boolean if the scene logic is paused
		void pause() { this->scene_paused = true; }		// Setter for the pause
		void resume() { this->scene_paused = false; }	// Setter to unpause

	protected:
		Lilac::World& create_world(std::string world_identifier);

		template<typename T>
		T* create_element(T element);

	};
	template<typename T>
	inline T* Scene::create_element(T element)
	{
		this->scene_ui_elements.push_back(std::make_shared<T>(element));
		return dynamic_cast<T*>(this->scene_ui_elements.back().get());
	}
}