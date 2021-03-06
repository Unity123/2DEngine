#pragma once
#include "Sprite.h"

class EXPORT CollisionSprite : public Sprite {
public:
	CollisionSprite();
	CollisionSprite(SDL_Texture* image, SDL_Renderer* render, SDL_FRect position);
	CollisionSprite(char* path, SDL_Renderer* render, SDL_FRect position);
	string Name();
	SDL_FRect boundingBox;
	bool Intersect(CollisionSprite other);
	bool Intersect(SDL_FRect other);
};