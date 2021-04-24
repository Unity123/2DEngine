#pragma once
#include "ForceSprite.h"

class EXPORT World : public Object
{
public:
	string Name();
	void Draw();
	void PhysicsProcess();
};

