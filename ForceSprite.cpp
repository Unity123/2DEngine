#include "ForceSprite.h"

string ForceSprite::Name()
{
	return "ForceSprite";
}

void ForceSprite::AddForce(float x, float y)
{
	this->velocityX += x;
	this->velocityY += y;
}

void ForceSprite::PhysicsProcess()
{
	for (Object* pointer : this->parent->children)
	{
		if ((pointer->Name() == "ForceSprite" || pointer->Name() == "CollisionSprite") && pointer != this) {
			if (((CollisionSprite*)pointer)->Intersect(*this)) {
				this->velocityX = 0;
				this->velocityY = 0;
				break;
			}
		}
	}
	this->position.x += this->velocityX;
	this->position.y += this->velocityY;
	this->velocityX -= 5;
	if (this->useGravity) {
		this->velocityY -= 9.81f;
	}
	else {
		this->velocityY -= 5;
	}
}
