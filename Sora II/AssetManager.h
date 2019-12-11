#pragma once
#include <vector>
#include <memory>
#include "Texture.h"

typedef std::shared_ptr<Lilac::Texture> TexturePtr;

namespace Lilac
{
	class AssetManager
	{
	private:
		struct TextureData {
			std::string id = "";
			TexturePtr texture = nullptr;
		};

		std::vector<TextureData> textures = {};

	public:
		TexturePtr& load_texture(const std::string id, const std::string texture_path); // Load a Texture to the database
		TexturePtr get_texture(const std::string id); // Retrieve a Texture from the database
		void unload_texture(const std::string id); // Destroy a single texture by id
		void destroy();
	};
}

