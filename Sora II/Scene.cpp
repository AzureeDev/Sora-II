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

std::shared_ptr<Lilac::UI::UIElement> Lilac::Scene::add_ui_element(std::shared_ptr<Lilac::UI::UIElement> element)
{
	this->scene_ui_elements.push_back(std::move(element));
	return this->scene_ui_elements.back();
}

std::shared_ptr<Lilac::UI::Image> Lilac::Scene::add_image(std::shared_ptr<Lilac::UI::Image> element)
{
	this->scene_ui_elements.push_back(element);
	return element;
}
