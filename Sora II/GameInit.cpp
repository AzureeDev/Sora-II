#include "GameInit.h"
#include "Globals.h"

using Lilac::UI::UIText, Lilac::UI::Image;

void Lilac::Scenes::GameInit::init()
{
	SDL_Log("GameInit init()");

	UIText* hi = this->create_text(UIText("Hello world", { 255, 150, 150, 255 }, 0, Globals::assets->get_font("escom48")));
	hi->set_position({ 400, 400 });
	hi->text()->set_text("Blah!");
}

void Lilac::Scenes::GameInit::update(const float dt)
{

}