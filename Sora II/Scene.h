#pragma once

/* Include base libraries for scenes */
#include <SDL.h>
#include <memory>
#include <vector>
#include <string>
#include "UIElement.h"
#include "Image.h"

namespace Lilac {
	class Scene
	{
	protected:
		bool scene_paused = false;						// When paused, the scene stops updating the logic
		std::vector<std::shared_ptr<Lilac::UI::UIElement>> scene_ui_elements = {};

	public:
		virtual ~Scene();								// Destructor, put cleanups here
		virtual void init();							// Executed on scene creation
		virtual void update(const float dt);			// Executed each frames, put logic in there, as well of inserting elements
		virtual void render();							// Executed each frames AFTER logic
		bool paused() { return this->scene_paused; }	// Boolean if the scene logic is paused
		void pause() { this->scene_paused = true; }		// Setter for the pause
		void resume() { this->scene_paused = false; }	// Setter to unpause

	protected:
		std::shared_ptr<Lilac::UI::UIElement> add_ui_element(std::shared_ptr<Lilac::UI::UIElement> element);
		std::shared_ptr<Lilac::UI::Image> add_image(std::shared_ptr<Lilac::UI::Image> element);
	};
}