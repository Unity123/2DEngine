#include "CollisionSprite.h"

CollisionSprite::CollisionSprite()
{
}

CollisionSprite::CollisionSprite(SDL_Texture * image, SDL_Renderer* render, SDL_Rect position)
{
	this->img = image;
	this->rnd = render;
	this->position = position;
}

CollisionSprite::CollisionSprite(char* path, SDL_Renderer* render, SDL_Rect position)
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
	return SDL_HasIntersection(&other.boundingBox, new SDL_Rect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}

bool CollisionSprite::Intersect(SDL_Rect other) {
	return SDL_HasIntersection(&other, new SDL_Rect{ boundingBox.x + position.x, boundingBox.y + position.y, boundingBox.w, boundingBox.h });
}