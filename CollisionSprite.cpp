#include "CollisionSprite.h"

CollisionSprite::CollisionSprite()
{
}

CollisionSprite::CollisionSprite(SDL_Texture * image, SDL_Renderer* render, SDL_FRect position)
{
	this->img = image;
	this->rnd = render;
	this->position = position;
}

CollisionSprite::CollisionSprite(char* path, SDL_Renderer* render, SDL_FRect position)
{
	this->img = IMG_LoadTexture(render, path);
	this->rnd = render;
	this->position = position;
}

string CollisionSprite::Name()
{
	return "CollisionSprite";
}

bool CollisionSprite::Intersect(CollisionSprite other) {
	// If one rectangle is on left side of other
	if (other.boundingBox.x + other.position.x > boundingBox.x + boundingBox.w + position.x || boundingBox.x + position.x > other.boundingBox.x + other.boundingBox.w + other.position.x)
		return false;

	// If one rectangle is above other
	if (other.boundingBox.y + other.position.y + other.boundingBox.h < boundingBox.y + position.y || boundingBox.y + position.y < other.boundingBox.y + other.boundingBox.h + other.position.y)
		return false;

	return true;
	//return SDL_HasIntersection(&other.boundingBox, new SDL_FRect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}

bool CollisionSprite::Intersect(SDL_FRect other) {
	// If one rectangle is on left side of other
	if (other.x > boundingBox.x + boundingBox.w + position.x || boundingBox.x + position.x > other.x + other.w)
		return false;

	// If one rectangle is above other
	if (other.y < boundingBox.y + position.y || boundingBox.y + position.y < other.y + other.h)
		return false;

	return true;
	//return SDL_HasIntersection(&other, new SDL_FRect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}