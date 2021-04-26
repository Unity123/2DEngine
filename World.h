#pragma once
#include "ForceSprite.h"
#include "AudioSource.h"

class EXPORT World : public Object
{
public:
	World();
	string Name();
	void Draw();
	void PhysicsProcess();
	float scrollX;
	float scrollY;
};

