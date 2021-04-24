#include "World.h"
#include <stdio.h>

World::World()
{
}

string World::Name()
{
	return "World";
}

void World::Draw()
{
	for (Object* pointer : this->children) {
		if (dynamic_cast<AudioSource*>(pointer) == nullptr) {
			printf("yeet\n");
			dynamic_cast<Sprite*>(pointer)->Draw();
			continue;
		}
		printf(":(\n");
	}
}

void World::PhysicsProcess()
{
	for (Object* pointer : this->children) {
		if (dynamic_cast<ForceSprite*>(pointer) != nullptr) {
			((ForceSprite*)pointer)->PhysicsProcess();
		}
	}
}
