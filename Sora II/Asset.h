#pragma once
#include <SDL.h>
#include <string>
#include <filesystem>

/*
	Asset
	Represents a living asset (texture, sfx, music, font...)
	This is the base class, use a child class to create assets.
*/

namespace Lilac
{
	template <typename AssetType>
	class Asset
	{
	protected:
		AssetType asset = nullptr;
		std::string asset_name = "";
		std::string asset_path = "";
		uint64_t asset_size = 0;
		bool asset_path_correct = false;

	public:
		Asset(std::string filepath); // Constructor, fill basic data
		virtual ~Asset() {}; // Virtual destructor, unload the asset

		const std::string& name() { return this->asset_name; }; // Asset name getter
		const std::string& path() { return this->asset_path; }; // Asset path getter
		const uint64_t size() { return this->asset_size; }; // Asset size getter
		const bool path_correct() { return this->asset_path_correct; }; // Is the path correct?

		virtual int load() = 0; // [Pure Virtual] Returns 1 on success, 0 on failure
		virtual AssetType get() { return this->asset; }; // Return the asset, whatever it is
	};

	/* Try first seeing if the asset exists, then fill the data in */
	template<typename AssetType>
	inline Lilac::Asset<AssetType>::Asset(std::string filepath)
	{
		if (filepath == "TEXT_ASSET")
		{
			/* Text textures doesn't have file data since we create it ourselves. */
			this->asset_name = "TEXT_ASSET";
			this->asset_path = "";
			this->asset_size = 0;
			return;
		}

		try
		{
			if (std::filesystem::exists(std::filesystem::path(filepath)))
			{
				struct stat stat_buffer;

				this->asset_path = filepath;
				this->asset_name = std::filesystem::path(filepath).filename().generic_u8string();

				int res = stat(filepath.c_str(), &stat_buffer);
				this->asset_size = res == 0 ? stat_buffer.st_size : 0;

				this->asset_path_correct = true;
			}
			else
			{
				throw std::exception("Cannot open the asset %s. It doesn't exist!");
			}
		}
		catch (std::exception exception)
		{
			SDL_Log(exception.what(), filepath.c_str());
		}
	}
}
	