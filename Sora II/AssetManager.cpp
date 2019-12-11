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

void Lilac::AssetManager::destroy()
{
	this->textures.clear();
}
