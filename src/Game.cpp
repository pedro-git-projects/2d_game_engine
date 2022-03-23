#include "Game.h"
#include "Logger.h"
#include "glm/fwd.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <glm/glm.hpp>
#include <cstddef>
#include <iostream>
#include <SDL2/SDL.h>

Game::Game() {
	isRunning = false;
	Logger::Log("Game constructor invoked");
}

Game::~Game() {
	Logger::Log("Game destructor invoked");
}

void Game::Initialize() {
	/* Initialize SDL */
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Logger::Err("Failed to initialize SDL");
		return;
	}
	/* Creating a display mode struct and populating it with the first monitor specs */
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	/* Setting width and height with displayMode */
	windoWidth = 800; // displayMode.w;
	windowHeight = 600; // displayMode.h;
	/* Populate window pointer */
	window = SDL_CreateWindow(
			NULL, 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			windoWidth,
			windowHeight,
			SDL_WINDOW_BORDERLESS
		);	
	if(!window) {
		Logger::Err("Failed to create window");
		return;
	}
	/* Populate renderer pointer*/
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!renderer) {
		Logger::Err("Failed to create renderer");
		return;
	}
	/* Changing video mode to real full screen */
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	/* Nothing failed, engine is running */
	isRunning = true;
}

void Game::Run() { 
	Setup();
	while (isRunning) {
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
				break;
		}
	}
}

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::Setup() {
	playerPosition = glm::vec2(10.0, 20.0);
	playerVelocity = glm::vec2(100.0, 0.0);
}

void Game::Update() {
	/* Correcting framerate with SDL_Delay to cap framerate */
	int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
	if(timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME) {
		SDL_Delay(timeToWait);
	}

	/* Difference in ticks from last frame casted into seconds */
	double deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;

	/* Sotring "previous" frametime */
    millisecsPreviousFrame = SDL_GetTicks();

	/* Incrementing player position accounting for the delta time */
    playerPosition.x += playerVelocity.x * deltaTime;
    playerPosition.y += playerVelocity.y * deltaTime;

}

void Game::Render() {
	/* Setting background color */
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	SDL_RenderClear(renderer);

	/* Render PNG */
	SDL_Surface* surface =	IMG_Load("./assets/images/tank-tiger-right.png"); /*create surface pointer*/
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); /*create texture pointer*/
	SDL_FreeSurface(surface); /*  Destroy typesurface */
	/* Creating destinationRect using playerPosition */
	SDL_Rect destinationRect = {
        static_cast<int>(playerPosition.x), 
        static_cast<int>(playerPosition.y), 
        32,
        32
    };

	SDL_RenderCopy(renderer, texture, NULL, &destinationRect); /* Render texure on destinationRect */
	SDL_DestroyTexture(texture); /* Destroy texture */
	
	/* Displaying render */
	SDL_RenderPresent(renderer);
}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
