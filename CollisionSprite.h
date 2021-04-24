#pragma once
#include "Sprite.h"

class EXPORT CollisionSprite : public Sprite {
public:
	string Name();
	SDL_Rect boundingBox;
	bool Intersect(CollisionSprite other);
	bool Intersect(SDL_Rect other);
};