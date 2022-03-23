#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
	private:
		bool isRunning;
		SDL_Window* window; 
		SDL_Renderer* renderer; 

	public:
		Game(); /* Constructor */
		~Game(); /* Destructor */	
		void Initialize();
		void Run();
		void ProcessInput();
		void Update();
		void Render();
		void Destroy();

		int windoWidth;
		int windowHeight;
};

#endif
