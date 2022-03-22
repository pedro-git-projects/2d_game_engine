#ifndef GAME_H
#define GAME_H

class Game {
	private:

	public:
		Game(); /* Constructor */
		~Game(); /* Destructor */	
		void Initialize();
		void Run();
		void ProcessInput();
		void Update();
		void Render();
		void Destroy();
};

#endif
