#pragma once
#include "ForceSprite.h"

class EXPORT World : public Object
{
public:
	World();
	string Name();
	void Draw();
	void PhysicsProcess();
};

