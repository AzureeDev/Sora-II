#include "Scene.h"

Lilac::Scene::~Scene()
{
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
	for (auto& ui_element : this->scene_ui_elements)
	{
		ui_element->render();
	}
}

Lilac::UI::Image* Lilac::Scene::create_image(Lilac::UI::Image element)
{
	this->scene_ui_elements.push_back(std::make_shared<Lilac::UI::Image>(element));
	return dynamic_cast<Lilac::UI::Image*>(this->scene_ui_elements.back().get());
}

Lilac::UI::UIText* Lilac::Scene::create_text(Lilac::UI::UIText element)
{
	this->scene_ui_elements.push_back(std::make_shared<Lilac::UI::UIText>(element));
	return dynamic_cast<Lilac::UI::UIText*>(this->scene_ui_elements.back().get());
}
