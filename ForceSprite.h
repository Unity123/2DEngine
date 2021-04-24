#pragma once
#include "CollisionSprite.h"
class ForceSprite : public CollisionSprite
{
public:
	string Name();
	void AddForce(float x, float y);
	float velocityX = 0;
	float velocityY = 0;
	bool useGravity = false;
	void PhysicsProcess();
};

