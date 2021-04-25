#include "Sprite.h"





Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Texture * image, SDL_Renderer* render, SDL_FRect position)
{
	this->img = image;
	this->rnd = render;
	this->position = position;
}

Sprite::Sprite(char* path, SDL_Renderer* render, SDL_FRect position)
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
	//printf("%i,%i,%i,%i", position.x, position.y, position.w, position.h);
	SDL_RenderCopyExF(rnd, img, NULL, &position, rotation, NULL, flip);
}