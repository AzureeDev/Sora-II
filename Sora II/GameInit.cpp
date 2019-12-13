#include "GameInit.h"
#include "Globals.h"

/*
	init()
	====================
	Initialize variables, assets, classes.. here. This function is called on scene creation.
*/
void Lilac::Scenes::GameInit::init()
{
	SDL_Log("GameInit init()");

	this->unit = Lilac::Units::Unit("sora", "assets/units/sora/sora_std");
	this->unit.set_position({ 820, 600 });
}

/*
	update()
	====================
	Handle the logic here - executed each frame
	NOTE: if the scene is paused, the execution is stopped!
*/
void Lilac::Scenes::GameInit::update(const float dt)
{

}

/*
	render()
	====================
	Place all your textures, and classes that needs to be shown here.
	The render keeps going even if the scene is paused. Destroy the class to clean it.
*/
void Lilac::Scenes::GameInit::render()
{
	this->unit.render();
}
