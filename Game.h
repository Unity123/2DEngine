#pragma once
#include "World.h"
#include <SDL_mixer.h>
class EXPORT Game
{
public:
	Game();
	~Game();
	void Start();
	void Run();
	World* world;
	SDL_Renderer* render;
	SDL_Window* window;
};