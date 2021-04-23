#include "CollisionSprite.h"

string CollisionSprite::Name()
{
	return "CollisionSprite";
}

bool CollisionSprite::Intersect(CollisionSprite other) {
	return SDL_HasIntersection(&other.boundingBox, &boundingBox);
}

bool CollisionSprite::Intersect(SDL_Rect other) {
	return SDL_HasIntersection(&other, &boundingBox);
}