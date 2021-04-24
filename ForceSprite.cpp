#include "ForceSprite.h"

ForceSprite::ForceSprite(SDL_Texture * image, SDL_Renderer* render, SDL_FRect position)
{
	this->img = image;
	this->rnd = render;
	this->position = position;
}

ForceSprite::ForceSprite(char* path, SDL_Renderer* render, SDL_FRect position)
{
	this->img = IMG_LoadTexture(render, path);
	this->rnd = render;
	this->position = position;
}

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
	this->velocityX *= 0.75f;
	if (this->useGravity) {
		this->velocityY -= 0.981f;
	}
	else {
		this->velocityY *= 0.75f;
	}
}
