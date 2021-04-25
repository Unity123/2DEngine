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
	//if (other.boundingBox.x + other.position.x >= boundingBox.x + boundingBox.w + position.x || boundingBox.x + position.x >= other.boundingBox.x + other.boundingBox.w + other.position.x)
	//	return false;

	// If one rectangle is above other
	//if (other.boundingBox.y + other.position.y + other.boundingBox.h < boundingBox.y + position.y || boundingBox.y + position.y < other.boundingBox.y + other.boundingBox.h + other.position.y)
	//	return false;

	return this->Intersect(SDL_FRect{ other.boundingBox.x + other.position.x, other.boundingBox.y + other.position.y, other.boundingBox.w, other.boundingBox.h });
	//return SDL_HasIntersection(&other.boundingBox, new SDL_FRect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}

bool CollisionSprite::Intersect(SDL_FRect other) {
	float leftOther = other.x;
	float rightOther = other.x + other.w;
	float topOther = other.y;
	float bottomOther = other.y + other.h;
	float leftThis = boundingBox.x + position.x;
	float rightThis = boundingBox.x + position.x + boundingBox.w;
	float topThis = boundingBox.y + position.y;
	float bottomThis = boundingBox.y + position.y + boundingBox.h;
	if (bottomThis < topOther)
	{
		return false;
	}

	if (topThis > bottomOther)
	{
		return false;
	}

	if (rightThis < leftOther)
	{
		return false;
	}

	if (leftThis > rightOther)
	{
		return false;
	}
	return true;
}