#include "GameInit.h"
#include "Globals.h"

using Lilac::UI::UIText, Lilac::UI::Image;

/*
	init()
	====================
	Initialize variables, assets, classes.. here. This function is called on scene creation.
*/
void Lilac::Scenes::GameInit::init()
{
	SDL_Log("GameInit init()");

	UIText* hi = this->create_text(UIText("Hello world", { 255, 150, 150, 255 }, 0, Globals::assets->get_font("escom48")));
	hi->set_position({ 400, 400 });
	hi->text()->set_text("Blah!");
}

/*
	update()
	====================
	Handle the logic here - executed each frame
	Note: if the scene is paused, the execution is stopped.
*/
void Lilac::Scenes::GameInit::update(const float dt)
{

}

/*
	render()
	====================
	Place all your textures, and classes that needs to be shown here.
	Note: when using create_image / create_text [...], rendering is automatically handled, layered by order of creation.
	The render keeps going even if the scene is paused. Destroy the class to clean it.
*/

/*
void Lilac::Scenes::GameInit::render()
{
}
*/