#include "Engine.h"
#include "Globals.h"
#include "physfs.h"

int main(int argc, char* argv[])
{
	// Init Archive library
	PHYSFS_init(argv[0]);

	Lilac::Engine engine;

	// Init Engine
	engine.init_engine();

	// Free Archive
	PHYSFS_deinit();

	return 0;
}