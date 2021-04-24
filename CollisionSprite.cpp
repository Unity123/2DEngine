#include "CollisionSprite.h"

string CollisionSprite::Name()
{
	return "CollisionSprite";
}

bool CollisionSprite::Intersect(CollisionSprite other) {
	return SDL_HasIntersection(&other.boundingBox, new SDL_Rect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}

bool CollisionSprite::Intersect(SDL_Rect other) {
	return SDL_HasIntersection(&other, new SDL_Rect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}