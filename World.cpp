#include "World.h"

string World::Name()
{
	return "World";
}

void World::Draw()
{
	for (Object* pointer : this->children) {
		if (pointer->Name() != "Object" && pointer->Name() != "AudioSource") {
			((Sprite*)pointer)->Draw();
		}
	}
}

void World::PhysicsProcess()
{
	for (Object* pointer : this->children) {
		if (pointer->Name() == "ForceSprite") {
			((ForceSprite*)pointer)->PhysicsProcess();
		}
	}
}
