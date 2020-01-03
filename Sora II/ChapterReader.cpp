#include "Globals.h"
#include "ChapterReader.h"

using tinyxml2::XMLAttribute, tinyxml2::XMLDocument, tinyxml2::XMLElement;

const std::string NOVEL_EXTENSION = "nvl";

Lilac::ChapterReader::ChapterReader()
{
}

void Lilac::ChapterReader::load_chapter(const std::string& xml_path)
{
	auto chapter_path = "novel/" + xml_path + "." + NOVEL_EXTENSION;

	if (this->chapter_document.LoadFile(chapter_path.c_str()) != tinyxml2::XML_SUCCESS)
	{
		SDL_Log("ChapterReader constructor: Error loading %s : Path incorrect? %s", xml_path.c_str(), chapter_path.c_str());
		return;
	}

	SDL_Log("ChapterReader: Reading %s - %s", xml_path.c_str(), this->get_chapter_title().c_str());
}

const std::string Lilac::ChapterReader::get_chapter_title()
{
	std::string title = "";
	title = this->chapter_document.FirstChildElement("Chapter")->FindAttribute("name")->Value();

	if (title != "")
	{
		return title;
	}

	return "[NO TITLE]";
}
