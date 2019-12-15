#include "AssetManager.h"
const std::string TEXTURE_EXTENSION = ".tga";

TexturePtr& Lilac::AssetManager::load_texture(const std::string id, const std::string texture_path)
{
	TextureData data;
	data.id = id;
	data.texture = std::shared_ptr<Texture>(new Texture(texture_path + TEXTURE_EXTENSION));

	this->textures.push_back(std::move(data));

	return this->textures.back().texture;
}

TexturePtr Lilac::AssetManager::get_texture(const std::string id)
{
	for (auto& texture : this->textures)
	{
		if (texture.id == id)
		{
			return texture.texture;
		}
	}

	SDL_Log("Lilac::AssetManager::get_texture : No texture found with the id %s", id.c_str());
	return nullptr;
}

void Lilac::AssetManager::unload_texture(const std::string id)
{
	for (size_t i = 0; i < this->textures.size(); ++i)
	{
		if (this->textures[i].id == id)
		{
			this->textures.erase(this->textures.begin() + i);
			break;
		}
	}
}

FontPtr& Lilac::AssetManager::load_font(const std::string id, const std::string font_path, const int font_size_pt)
{
	FontData data;
	data.id = id;
	data.font = std::shared_ptr<Font>(new Font(font_path, font_size_pt));

	this->fonts.push_back(std::move(data));

	return this->fonts.back().font;
}

FontPtr Lilac::AssetManager::get_font(const std::string id)
{
	for (auto& font : this->fonts)
	{
		if (font.id == id)
		{
			return font.font;
		}
	}

	SDL_Log("Lilac::AssetManager::get_font : No font found with the id %s", id.c_str());
	return nullptr;
}

void Lilac::AssetManager::destroy()
{
	this->textures.clear();
	this->fonts.clear();
}
