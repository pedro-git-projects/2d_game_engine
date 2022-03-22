#include "Game.h"
#include <iostream>
#include <ostream>

/* Constructor*/
Game::Game() {
	std::cout << "Game constructor invoked" << std::endl;
}

Game::~Game() {
	std::cout << "Game destructor invoked" << std::endl;
}

void Game::Initialize(){}

void Game::Run(){}

void Game::ProcessInput() {}

void Game::Update(){}

void Game::Render(){}

void Game::Destroy(){}
