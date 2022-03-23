#include "Game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>
#include <SDL2/SDL.h>

/* Constructor*/
Game::Game() {
	isRunning = false;
	std::cout << "Game constructor invoked" << std::endl;
}

Game::~Game() {
	std::cout << "Game destructor invoked" << std::endl;
}

void Game::Initialize() {
	/* Initialize SDL */
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to initialize SDL" << std::endl;
		return;
	}
	/* Creating a display mode struct and populating it with the first monitor specs */
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	/* Setting width and height with displayMode */
	windoWidth = displayMode.w;
	windowHeight = displayMode.h;
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
		std::cerr << "Failed to create window" << std::endl;
	}
	/* Populate renderer pointer*/
	renderer = SDL_CreateRenderer(window, -1, 0);
	if(!renderer) {
		std::cerr << "Failed to create renderer" << std::endl;
		return;
	}
	/* Changing video mode to real full screen */
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	/* Nothing failed, engine is running */
	isRunning = true;
}

void Game::Run() { 
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

void Game::Update(){}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
