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
	if (velocityX > 0.5f) {
		velocityX = 0.5f;
	}
	if (velocityY > 0.5f) {
		velocityY = 0.5f;
	}
	this->position.x += this->velocityX;
	this->position.y += this->velocityY;
	for (Object* pointer : this->parent->children)
	{
		if ((dynamic_cast<CollisionSprite*>(pointer) != nullptr) && pointer != (Object*)this) {
			//printf("q");
			if (((CollisionSprite*)pointer)->Intersect(*this)) {
				//printf("l");
				this->position.x -= 2*velocityX;
				this->position.y -= 2*velocityY;
				break;
			}
		}
	}
	if (velocityX >= 0) {
		velocityX -= 0.0005f;
	}
	else {
		velocityX += 0.0005f;
	}
	if (this->useGravity) {
		this->velocityY -= 0.0981f;
	}
	else {
		if (velocityY >= 0) {
			velocityY -= 0.0005f;
		}
		else {
			velocityY += 0.0005f;
		}
	}
}
