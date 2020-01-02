#pragma once
#include "Scene.h"

namespace Lilac::Scenes
{
	using Lilac::UI::Image;

	class VNCharacter : public Scene
	{
	private:
		Image* character_artwork = nullptr;
		std::string character_id = "";
		bool character_active = false;
		bool character_flipped = false;
		std::string character_artwork_id = "";
		std::string character_name = "";

	public:
		void init();
		void set_flipped(const bool flipped_state);
		void set_active(const bool active_state);
		Lilac::UI::Image* artwork();
		void create_character(const std::string character_id, const std::string animation = "stand1");
		void say(const std::string text, const std::string animation = "");
		void update(const float dt);
	};
}