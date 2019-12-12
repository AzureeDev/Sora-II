#include "GameInit.h"
#include "Globals.h"


void Lilac::Scenes::GameInit::init()
{
	SDL_Log("GameInit init()");

	this->textures.push_back(std::make_unique<Lilac::UI::Image>(Lilac::UI::Image("assets/error")));
}

void Lilac::Scenes::GameInit::update(const float dt)
{
	for (auto& image : this->textures)
	{
		image->render();
	}
}
