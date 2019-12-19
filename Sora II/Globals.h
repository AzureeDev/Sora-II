#pragma once
#include <memory>
#include "Utils.h"
#include "Engine.h"
#include "Lua.h"
#include "AssetManager.h"
#include "SceneManager.h"

struct Globals
{
	static int mousePositionX;
	static int mousePositionY;
	static Lilac::Engine* engine;
	static std::unique_ptr<Lilac::Lua> lua;
	static std::unique_ptr<Lilac::AssetManager> assets;
	static std::unique_ptr<Lilac::SceneManager> scenes;
};

