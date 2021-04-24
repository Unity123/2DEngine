#pragma once
#include "Sprite.h"

class EXPORT CollisionSprite : public Sprite {
public:
	CollisionSprite();
	CollisionSprite(SDL_Texture* image, SDL_Renderer* render, SDL_Rect position);
	CollisionSprite(char* path, SDL_Renderer* render, SDL_Rect position);
	string Name();
	SDL_Rect boundingBox;
	bool Intersect(CollisionSprite other);
	bool Intersect(SDL_Rect other);
};