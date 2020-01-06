#pragma once
#include <SDL.h>

namespace Lilac::Utils
{
	class TickTimer
	{
	private:
		Uint32 start_ticks = 0;
		Uint32 paused_ticks = 0;
		bool paused = false;
		bool started = false;

	public:
		// Start the timer
		void start();
		// Stop the timer and resets
		void stop();
		// Pause the timer
		void pause();
		// Unpause the timer
		void unpause();

		Uint32 get_ticks();
		bool is_started();
		bool is_paused();
	};
}