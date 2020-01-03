#pragma once
#include <string>
#include "tinyxml2.h"

namespace Lilac
{
	class ChapterReader
	{
	private:
		tinyxml2::XMLDocument chapter_document;

	public:
		ChapterReader();
		void load_chapter(const std::string& xml_path);
		const std::string get_chapter_title();
	};
}
	

