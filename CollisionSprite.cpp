#include "CollisionSprite.h"

bool CollisionSprite::Intersect(CollisionSprite other) {
	return other.boundingBox.x >= boundingBox.x || other.boundingBox.y >= boundingBox.y || other.boundingBox.w <= boundingBox.w || other.boundingBox.h <= boundingBox.h;
}

bool CollisionSprite::Intersect(SDL_Rect other) {

}