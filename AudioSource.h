#pragma once
#include "Object.h"
#include <SDL.h>
#include <SDL_mixer.h>
using namespace std;

class AudioSource : public Object
{
public:
	AudioSource(string path, bool isMusic);
	void Play();
	void Pause();
	void Stop();
private:
	Mix_Music* music;
	Mix_Chunk* chunk;
	bool isMusic;
};

