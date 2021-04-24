#pragma once
#include "Sprite.h"

class CollisionSprite : public Sprite {
public:
	string Name();
	SDL_Rect boundingBox;
	bool Intersect(CollisionSprite other);
	bool Intersect(SDL_Rect other);
};