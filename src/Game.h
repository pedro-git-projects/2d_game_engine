#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {
	private:
		bool isRunning;
        int millisecsPreviousFrame = 0;
		SDL_Window* window; 
		SDL_Renderer* renderer; 

	public:
		Game(); /* Constructor */
		~Game(); /* Destructor */	
		void Initialize();
		void Setup();
		void Run();
		void ProcessInput();
		void Update();
		void Render();
		void Destroy();

		int windoWidth;
		int windowHeight;
};

#endif
