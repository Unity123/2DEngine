#pragma once
#include "Sprite.h"

class CollisionSprite : Sprite {
public:
	SDL_Rect boundingBox;
	bool Intersect(CollisionSprite other);
	bool Intersect(SDL_Rect other);
};