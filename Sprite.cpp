#include "Sprite.h"





Sprite::Sprite(SDL_Texture * image, SDL_Renderer* render, SDL_Rect position)
{
	this->img = image;
	this->rnd = render;
	this->position = position;
}

Sprite::Sprite(char* path, SDL_Renderer* render, SDL_Rect position)
{
	this->img = IMG_LoadTexture(render, path);
	this->rnd = render;
	this->position = position;
}

Sprite::~Sprite()
{
}

string Sprite::Name()
{
	return "Sprite";
}

void Sprite::Draw() {
	SDL_RenderCopyEx(rnd, img, NULL, &position, rotation, NULL, flip);
}