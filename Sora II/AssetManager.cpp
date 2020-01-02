#include "AssetManager.h"
#include "Globals.h"

const std::string TEXTURE_EXTENSION = ".tga";
const std::string MUSIC_EXTENSION = ".ogg";
const std::string SFX_EXTENSION = ".wav";

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
	auto iterator = std::find_if(this->textures.begin(), this->textures.end(), [&](const TextureData& d) { return d.id == id; });

	if (iterator != this->textures.end())
	{
		return iterator->texture;
	}

	SDL_Log("Lilac::AssetManager::get_texture : No texture found with the id %s", id.c_str());
	return nullptr;
}

void Lilac::AssetManager::unload_texture(const std::string id)
{
	auto iterator = std::find_if(this->textures.begin(), this->textures.end(), [&](const TextureData& d) { return d.id == id; });

	if (iterator != this->textures.end())
	{
		this->textures.erase(iterator);
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
	auto iterator = std::find_if(this->fonts.begin(), this->fonts.end(), [&](const FontData& d) { return d.id == id; });

	if (iterator != this->fonts.end())
	{
		return iterator->font;
	}

	SDL_Log("Lilac::AssetManager::get_font : No font found with the id %s", id.c_str());
	return nullptr;
}

MusicPtr& Lilac::AssetManager::load_music(const std::string id, const std::string music_path)
{
	MusicData data;
	data.id = id;
	data.music = std::shared_ptr<Music>(new Music(music_path + MUSIC_EXTENSION));

	this->musics.push_back(std::move(data));

	return this->musics.back().music;
}

MusicPtr Lilac::AssetManager::get_music(const std::string id)
{
	auto iterator = std::find_if(this->musics.begin(), this->musics.end(), [&](const MusicData& d) { return d.id == id; });

	if (iterator != this->musics.end())
	{
		return iterator->music;
	}

	SDL_Log("Lilac::AssetManager::get_music : No music found with the id %s", id.c_str());
	return nullptr;
}

SFXPtr& Lilac::AssetManager::load_sfx(const std::string id, const std::string sfx_path)
{
	SFXData data;
	data.id = id;
	data.sfx = std::shared_ptr<SFX>(new SFX(sfx_path + SFX_EXTENSION));

	this->sfxs.push_back(std::move(data));

	return this->sfxs.back().sfx;
}

SFXPtr Lilac::AssetManager::get_sfx(const std::string id)
{
	auto iterator = std::find_if(this->sfxs.begin(), this->sfxs.end(), [&](const SFXData& d) { return d.id == id; });

	if (iterator != this->sfxs.end())
	{
		return iterator->sfx;
	}

	SDL_Log("Lilac::AssetManager::get_sfx : No SFX found with the id %s", id.c_str());
	return nullptr;
}

std::vector<Lilac::AssetManager::TextureData>& Lilac::AssetManager::all_textures()
{
	return this->textures;
}

void Lilac::AssetManager::destroy()
{
	this->textures.clear();
	this->fonts.clear();
	this->musics.clear();
	this->sfxs.clear();
}
