#pragma once
#include "CollisionSprite.h"
class EXPORT ForceSprite : public CollisionSprite
{
public:
	ForceSprite(SDL_Texture* image, SDL_Renderer* render, SDL_FRect position);
	ForceSprite(char* path, SDL_Renderer* render, SDL_FRect position);
	string Name();
	void AddForce(float x, float y);
	float velocityX = 0;
	float velocityY = 0;
	bool useGravity = false;
	void PhysicsProcess();
};

