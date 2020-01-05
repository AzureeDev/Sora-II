#pragma once
#include "Scene.h"
#include "tinyxml2.h"
#include "ChapterReader.h"
#include "VNScene.h"

namespace Lilac
{
	class VNManager : public Scene
	{
	private:
		int current_dialog_id = 0;
		bool allowed_dialog_skip = false;
		const tinyxml2::XMLElement* current_dialog_element = nullptr;
		Lilac::ChapterReader chapter_reader;

		// Ptr to elements
		Lilac::Scenes::VNBubble* bubble = nullptr;
		Lilac::Scenes::VNScene* scene = nullptr;
		Lilac::Scenes::VNCharacter* l_unit = nullptr;
		Lilac::Scenes::VNCharacter* r_unit = nullptr;

	public:
		void init();
		void read_next_dialog();
		void update(const float dt);

	private:
		void _pre_init_chapter();
		void _set_new_actor();
	};
}