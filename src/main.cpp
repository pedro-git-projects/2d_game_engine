#include <iostream>
#include "./Game/Game.h"

int main(int argc, char* argv[]) {
	Game game; /* Since new was not used the game object will be stored in the Stack */
	/* Thus it will be destroyed when it goes out of scope */

	game.Initialize();
	game.Run();
	game.Destroy();
	
	return 0;
}
