#include "Engine.h"
#include "Globals.h"
#include "Texture.h"

Lilac::Engine::Engine()
{
	this->init_globals();
	this->init_base_assets();
	this->update();
	this->cleanup();
}

void Lilac::Engine::init_globals()
{
	Globals::engine = std::make_unique<Lilac::Engine>(*this);
	Globals::assets = std::make_unique<Lilac::AssetManager>(AssetManager());
}

void Lilac::Engine::init_base_assets()
{
	Globals::assets->load_texture("ui_cursor_normal", "assets/guis/ui_cursor_normal");
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
	Globals::assets->destroy();
	this->sdl_instance.destroy();
}