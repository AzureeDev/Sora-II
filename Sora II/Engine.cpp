#include "Engine.h"
#include "Globals.h"
#include "GameInit.h"

const int FPS_MAX = 90;
const int FPS_TICKS_PER_FRAME = 1000 / FPS_MAX;

Lilac::Engine::Engine()
{
}

void Lilac::Engine::init_engine()
{
	this->init_globals();
	this->init_base_assets();
	this->init_lua();
	this->init_entry_scene();
	this->update();
	this->cleanup();
}

void Lilac::Engine::init_globals()
{
	Globals::engine = std::make_unique<Lilac::Engine>(*this);
	Globals::lua = std::unique_ptr<Lilac::Lua>(new Lua);
	Globals::assets = std::make_unique<Lilac::AssetManager>(AssetManager());
	Globals::scenes = std::make_unique<Lilac::SceneManager>(SceneManager());
}

void Lilac::Engine::init_base_assets()
{
	/* Init cursor */
	this->cursor = std::make_shared<Lilac::UI::Image>(Lilac::UI::Image("assets/guis/ui_cursor_normal"));

	/* Load fonts */
	Globals::assets->load_font("escom16", "assets/fonts/escom.ttf", 16);
	Globals::assets->load_font("escom24", "assets/fonts/escom.ttf", 24);
	Globals::assets->load_font("escom32", "assets/fonts/escom.ttf", 32);
	Globals::assets->load_font("escom48", "assets/fonts/escom.ttf", 48);
}

void Lilac::Engine::init_lua()
{
}

void Lilac::Engine::init_entry_scene()
{
	Globals::scenes->create_scene({ "GameInit", std::shared_ptr<Lilac::Scenes::GameInit>(new Lilac::Scenes::GameInit) });
}

void Lilac::Engine::update()
{
	// Define variables to get a solid deltatime
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	float deltaTime = 0;

	while (this->running)
	{
		this->cap_timer.start();

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

			Globals::scenes->event(event);
		}

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = ((NOW - LAST) / (float)SDL_GetPerformanceFrequency());

		SDL_RenderClear(this->sdl_instance.get_renderer());
		Globals::scenes->update(deltaTime);
		Globals::scenes->render();
		this->cursor->set_position({ Globals::mousePositionX, Globals::mousePositionY });
		this->cursor->render();
		SDL_RenderPresent(this->sdl_instance.get_renderer());

		int frame_ticks = this->cap_timer.get_ticks();
		if (frame_ticks < FPS_TICKS_PER_FRAME)
		{
			SDL_Delay(FPS_TICKS_PER_FRAME - frame_ticks);
		}
	}
}

void Lilac::Engine::cleanup()
{
	Globals::assets->destroy();
	this->sdl_instance.destroy();
}