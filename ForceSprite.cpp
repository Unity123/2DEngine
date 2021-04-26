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
				this->position.x -= velocityX;
				this->position.y -= velocityY;
				break;
			}
		}
	}
	if (frame >= 5) {
		if (velocityX > 0) {
			velocityX -= 0.05f;
		}
		else if (velocityX < 0) {
			velocityX += 0.05f;
		}
	}
	if (frame >= 5) {
		if (this->useGravity) {
			this->velocityY -= 0.0981f;
		}
		else {
			if (velocityY > 0) {
				velocityY -= 0.05f;
			}
			else if (velocityY < 0) {
				velocityY += 0.05f;
			}
		}
	}
	frame++;
	if (frame >= 5) {
		frame = 0;
	}
	if (abs(0 - velocityX) < 0.000001f) {
		velocityX = 0;
	}if (abs(0 - velocityY) < 0.000001f) {
		velocityY = 0;
	}
}
