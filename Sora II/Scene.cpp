#include "Scene.h"

Lilac::Scene::~Scene()
{
	this->scene_ui_elements.clear();
	SDL_Log("Destroyed the Scene: %s", this->scene_identifier.c_str());
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
		ui_element.ui_element->event(event);
	}
}

void Lilac::Scene::_private_update(const float dt)
{
	this->scene_timer += dt;
}

void Lilac::Scene::_set_scene_name(const std::string scene_identifier)
{
	this->scene_identifier = scene_identifier;
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
		ui_element.ui_element->render();
	}
}

Lilac::World& Lilac::Scene::create_world(const std::string world_identifier)
{
	this->scene_world = World(world_identifier);

	return this->scene_world;
}

void Lilac::Scene::set_element_layer(const std::string id, const int layer)
{
	for (auto& element : this->scene_ui_elements)
	{
		if (element.identifier == id)
		{
			element.layer = layer;

			this->trigger_layer_sorting();
			return;
		}
	}

	SDL_Log("Lilac::Scene::set_element_layer : Element %s not found.", id.c_str());
}

void Lilac::Scene::remove_element(const std::string id)
{
	for (size_t i = 0; i < this->scene_ui_elements.size(); ++i)
	{
		if (this->scene_ui_elements[i].identifier == id)
		{
			this->scene_ui_elements.erase(this->scene_ui_elements.begin() + i);
			this->trigger_layer_sorting();
			return;
		}
	}

	SDL_Log("Lilac::Scene::remove_element : Element %s not found.", id.c_str());
}

void Lilac::Scene::clear_all_elements()
{
	this->scene_ui_elements.clear();
}

void Lilac::Scene::trigger_layer_sorting()
{
	std::sort(this->scene_ui_elements.begin(), this->scene_ui_elements.end(), [](UIElementDefinition& a, UIElementDefinition& b)
		{
			return a.layer < b.layer;
		}
	);
}
