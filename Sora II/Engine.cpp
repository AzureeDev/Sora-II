#include "Engine.h"
#include "Globals.h"
#include "Texture.h"

Lilac::Engine::Engine()
{
	this->init_globals();
	this->update();
	this->cleanup();
}

void Lilac::Engine::init_globals()
{
	Globals::engine = std::make_unique<Lilac::Engine>(*this);
}

void Lilac::Engine::update()
{
	while (this->running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EventType::SDL_QUIT:
				this->running = false;
				break;
			}
		}

		SDL_RenderClear(this->sdl_instance.get_renderer());
		SDL_RenderPresent(this->sdl_instance.get_renderer());
	}
}

void Lilac::Engine::cleanup()
{
	this->sdl_instance.destroy();
}