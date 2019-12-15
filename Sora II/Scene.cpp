#include "Scene.h"

Lilac::Scene::~Scene()
{
}

void Lilac::Scene::init()
{
}

void Lilac::Scene::update(const float dt)
{
}

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
