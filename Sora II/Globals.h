#pragma once
#include <memory>
#include "Archive.h"
#include "Utils.h"
#include "Engine.h"
#include "Lua.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "MusicManager.h"
#include "VNManager.h"

struct Globals
{
	static int mousePositionX;
	static int mousePositionY;
	static Lilac::Engine* engine;
	// Lilac::Lua
	static std::unique_ptr<Lilac::Lua> lua;
	// Lilac::Archive
	static std::unique_ptr<Lilac::Archive> archive;
	// Lilac::AssetManager
	static std::unique_ptr<Lilac::AssetManager> assets;
	// Lilac::SceneManager
	static std::unique_ptr<Lilac::SceneManager> scenes;
	// Lilac::VNManager
	static Lilac::VNManager* vn_manager;
};

