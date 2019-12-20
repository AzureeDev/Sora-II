#include "Scene.h"

Lilac::Scene::~Scene()
{
	this->scene_ui_elements.clear();
}

/*
	init()
	====================
	Initialize variables, assets, classes.. here. This function is called on scene creation.
*/
void Lilac::Scene::init()
{
}

/*
	event()
	====================
	Keyboard input, mouse clicks, all are handled and sent through here.
	Paused scenes do not catch any events.
*/
void Lilac::Scene::event(SDL_Event& event)
{
	for (auto& ui_element : this->scene_ui_elements)
	{
		ui_element->event(event);
	}
}

/*
	update()
	====================
	Handle the logic here - executed each frame
	Note: if the scene is paused, the execution is stopped.
*/
void Lilac::Scene::update(const float dt)
{
}

/*
	render()
	====================
	Place all your textures, and classes that needs to be shown here.
	Note: when using create_image / create_text [...], rendering is automatically handled, layered by order of creation.
	The render keeps going even if the scene is paused. Destroy the class to clean it.
*/
void Lilac::Scene::render()
{
	this->scene_world.render();

	for (auto& ui_element : this->scene_ui_elements)
	{
		ui_element->render();
	}
}

Lilac::World& Lilac::Scene::create_world(std::string world_identifier)
{
	this->scene_world = World(world_identifier);

	return this->scene_world;
}