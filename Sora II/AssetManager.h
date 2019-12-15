#pragma once
#include <vector>
#include <memory>
#include "Texture.h"
#include "Font.h"

typedef std::shared_ptr<Lilac::Texture> TexturePtr;
typedef std::shared_ptr<Lilac::Font> FontPtr;

namespace Lilac
{
	class AssetManager
	{
	private:
		struct TextureData {
			std::string id = "";
			TexturePtr texture = nullptr;
		};

		struct FontData {
			std::string id = "";
			FontPtr font = nullptr;
		};

		std::vector<TextureData> textures = {};
		std::vector<FontData> fonts = {};

	public:
		TexturePtr& load_texture(const std::string id, const std::string texture_path); // Load a Texture to the database
		TexturePtr get_texture(const std::string id); // Retrieve a Texture from the database
		void unload_texture(const std::string id); // Destroy a single texture by id
		FontPtr& load_font(const std::string id, const std::string font_path, const int font_size_pt); // Load a Font to the db
		FontPtr get_font(const std::string id); // Retrieve a Font from the db
		void destroy(); // Destroy all assets.
	};
}

