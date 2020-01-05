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

const std::string Lilac::ChapterReader::get_initial_l_unit_id()
{
	auto attribute = this->chapter_document.FirstChildElement("Chapter")->FindAttribute("initial_l_unit");

	if (attribute == nullptr)
	{
		return "none";
	}

	auto unit_id = attribute->Value();

	if (unit_id != "")
	{
		return unit_id;
	}

	return "none";
}

const std::string Lilac::ChapterReader::get_initial_r_unit_id()
{
	auto attribute = this->chapter_document.FirstChildElement("Chapter")->FindAttribute("initial_r_unit");

	if (attribute == nullptr)
	{
		return "none";
	}

	auto unit_id = attribute->Value();

	if (unit_id != "")
	{
		return unit_id;
	}

	return "none";
}

const std::vector<tinyxml2::XMLElement*> Lilac::ChapterReader::get_dialogs()
{
	auto root = this->chapter_document.FirstChildElement("Chapter");
	auto container = std::vector<tinyxml2::XMLElement*>();

	for (XMLElement* element = root->FirstChildElement("Dialog"); element != nullptr; element = element->NextSiblingElement("Dialog"))
	{
		container.push_back(element);
	}

	return container;
}

const tinyxml2::XMLElement* Lilac::ChapterReader::get_dialog_by_id(const int id)
{
	auto container = this->get_dialogs();

	for (const auto& item : container)
	{
		if (item->Attribute("id") == std::to_string(id).c_str())
		{
			return item;
		}
	}

	return nullptr;
}
