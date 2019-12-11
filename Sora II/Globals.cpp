#include "Globals.h"

std::unique_ptr<Lilac::Engine> Globals::engine = nullptr;
std::unique_ptr<Lilac::AssetManager> Globals::assets = nullptr;
std::unique_ptr<Lilac::SceneManager> Globals::scenes = nullptr;