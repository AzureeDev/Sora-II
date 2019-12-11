#pragma once
#include <memory>
#include "Engine.h"

struct Globals
{
	static std::unique_ptr<Lilac::Engine> engine;
};

