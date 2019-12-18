#pragma once
#include "UIElement.h"
#include "Texture.h"

namespace Lilac::UI
{
	class Button : public UIElement
	{
	private:
		std::shared_ptr<Lilac::Texture> button_texture = nullptr;

	public:
		Button() {};
		Button(std::string button_texture_path);

		virtual void render();
	};
}