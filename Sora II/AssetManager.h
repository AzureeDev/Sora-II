#pragma once
#include <vector>
#include <memory>
#include "Texture.h"
#include "Font.h"
#include "Music.h"
#include "SFX.h"

typedef std::shared_ptr<Lilac::Texture> TexturePtr;
typedef std::shared_ptr<Lilac::Font> FontPtr;
typedef std::shared_ptr<Lilac::Music> MusicPtr;
typedef std::shared_ptr<Lilac::SFX> SFXPtr;

namespace Lilac
{
	class AssetManager
	{
	private:
		struct TextureData { std::string id = ""; TexturePtr texture = nullptr; };
		struct FontData { std::string id = ""; FontPtr font = nullptr; };
		struct MusicData { std::string id = ""; MusicPtr music = nullptr; };
		struct SFXData { std::string id = ""; SFXPtr sfx = nullptr; };

		std::vector<TextureData> textures = {};
		std::vector<FontData> fonts = {};
		std::vector<MusicData> musics = {};
		std::vector<SFXData> sfxs = {};

	public:
		TexturePtr& load_texture(const std::string id, const std::string texture_path); // Load a Texture to the database
		TexturePtr get_texture(const std::string id); // Retrieve a Texture from the database
		void unload_texture(const std::string id); // Destroy a single texture by id
		FontPtr& load_font(const std::string id, const std::string font_path, const int font_size_pt); // Load a Font to the db
		FontPtr get_font(const std::string id); // Retrieve a Font from the db
		MusicPtr& load_music(const std::string id, const std::string music_path); // Load a Music to the db
		MusicPtr get_music(const std::string id); // Retrieve a Music from the db
		SFXPtr& load_sfx(const std::string id, const std::string sfx_path); // Load a SFX to the db
		SFXPtr get_sfx(const std::string id); // Retrieve a SFX from the db
		std::vector<Lilac::AssetManager::TextureData>& all_textures();
		void destroy(); // Destroy all assets.
	};
}

