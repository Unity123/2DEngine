#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Object.h"
#include "World.h"
using namespace std;
class EXPORT Sprite : public Object
{
public:
	Sprite();
	Sprite(SDL_Texture* image, SDL_Renderer* render, SDL_FRect position);
	Sprite(char* path, SDL_Renderer* render, SDL_FRect position);
	~Sprite();
	string Name();
	void Draw();
	SDL_Texture* img;
	SDL_Renderer* rnd;
	SDL_FRect position;
	SDL_FRect relativePosition;
	bool doesUseRelativePosition = false;
	float rotation;
	SDL_RendererFlip flip;
};