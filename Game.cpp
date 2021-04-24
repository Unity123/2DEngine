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
	if (!SDL_CreateWindowAndRenderer(640, 480, NULL, &window, &render)) {
		IMG_Init(IMG_INIT_PNG);
		Mix_Init(MIX_INIT_MP3);
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	}
}

void Game::Run() {
	SDL_SetRenderDrawColor(render, 25, 25, 25, 255);
	SDL_RenderClear(render);
	world->Draw();
	world->PhysicsProcess();
	SDL_RenderPresent(render);
}
