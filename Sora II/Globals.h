#pragma once
#include <memory>
#include "Engine.h"
#include "AssetManager.h"
#include "SceneManager.h"

struct Globals
{
	static std::unique_ptr<Lilac::Engine> engine;
	static std::unique_ptr<Lilac::AssetManager> assets;
	static std::unique_ptr<Lilac::SceneManager> scenes;
};

