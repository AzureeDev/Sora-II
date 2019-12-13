#include "GameInit.h"
#include "Globals.h"


void Lilac::Scenes::GameInit::init()
{
	SDL_Log("GameInit init()");

	this->texture = Lilac::UI::Image("assets/error");
	this->texture.set_position({ 820, 600 });
}

void Lilac::Scenes::GameInit::update(const float dt)
{
	this->texture.render();
}
