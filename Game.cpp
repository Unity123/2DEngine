#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Start()
{
	world = new World();
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(640, 480, NULL, &window, &render);
}

void Game::Run() {
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderClear(render);
	world->Draw();
	world->PhysicsProcess();
	SDL_RenderPresent(render);
}
