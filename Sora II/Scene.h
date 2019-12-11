#pragma once

/* Include base libraries for scenes */
#include <SDL.h>
#include <vector>
#include <string>

namespace Lilac {
	class Scene
	{
	protected:
		bool scene_paused = false;						// When paused, the scene stops updating the logic

	public:
		virtual ~Scene();								// Destructor, put cleanups here
		virtual void init();							// Executed on scene creation
		virtual void update(const float dt);			// Executed each frames, put logic in there, as well of inserting elements
		bool paused() { return this->scene_paused; }	// Boolean if the scene logic is paused
		void pause() { this->scene_paused = true; }		// Setter for the pause
		void resume() { this->scene_paused = false; }	// Setter to unpause
	};
}