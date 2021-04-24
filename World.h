#pragma once
#include "ForceSprite.h"

class World : public Object
{
public:
	string Name();
	void Draw();
	void PhysicsProcess();
};

