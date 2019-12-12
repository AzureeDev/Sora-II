#include "Engine.h"
#include "Globals.h"
#include "GameInit.h"

Lilac::Engine::Engine()
{
	this->init_globals();
	this->init_base_assets();
	this->init_entry_scene();
	this->update();
	this->cleanup();
}

void Lilac::Engine::init_globals()
{
	Globals::engine = std::make_unique<Lilac::Engine>(*this);
	Globals::assets = std::make_unique<Lilac::AssetManager>(AssetManager());
	Globals::scenes = std::make_unique<Lilac::SceneManager>(SceneManager());
}

void Lilac::Engine::init_base_assets()
{
	/* Init cursor */
	this->cursor = std::make_shared<Lilac::UI::Image>(Lilac::UI::Image("assets/guis/ui_cursor_normal"));
}

void Lilac::Engine::init_entry_scene()
{
	Globals::scenes->create_scene({ "GameInit", std::shared_ptr<Lilac::Scenes::GameInit>(new Lilac::Scenes::GameInit()) });
}

void Lilac::Engine::update()
{
	// Define variables to get a solid deltatime
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	float deltaTime = 0;

	while (this->running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EventType::SDL_MOUSEMOTION:
				SDL_GetMouseState(&Globals::mousePositionX, &Globals::mousePositionY);
				break;

			case SDL_EventType::SDL_QUIT:
				this->running = false;
				break;
			}
		}

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = ((NOW - LAST) / (float)SDL_GetPerformanceFrequency());

		SDL_RenderClear(this->sdl_instance.get_renderer());
		Globals::scenes->update(deltaTime);

		this->cursor->set_position({ Globals::mousePositionX, Globals::mousePositionY });
		this->cursor->render();
		SDL_RenderPresent(this->sdl_instance.get_renderer());
	}
}

void Lilac::Engine::cleanup()
{
	Globals::assets->destroy();
	this->sdl_instance.destroy();
}