#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Object.h"
using namespace std;
class Sprite : Object
{
public:
	Sprite(SDL_Texture* image, SDL_Renderer* render, SDL_Rect position);
	Sprite(string path, SDL_Renderer* render, SDL_Rect position);
	~Sprite();
	void Draw();
	SDL_Texture* img;
	SDL_Renderer* rnd;
	SDL_Rect position;
	float rotation;
	SDL_RendererFlip flip;
};

