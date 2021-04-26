#include "AudioSource.h"


AudioSource::AudioSource(char* path, bool isMusic)
{
	if (isMusic) {
		this->music = Mix_LoadMUS(path);
	}
	else {
		this->chunk = Mix_LoadWAV(path);
	}
	this->isMusic = isMusic;
}

void AudioSource::Play()
{
	if (isMusic) {
		Mix_PlayMusic(music, -1);
	}
	else {
		Mix_PlayChannel(-1, chunk, 1);
	}
}

void AudioSource::Pause()
{
	if (isMusic) {
		if (Mix_PausedMusic()) {
			Mix_ResumeMusic();
		}
		else {
			Mix_PauseMusic();
		}
	}
}

void AudioSource::Stop()
{
	if (isMusic) {
		Mix_HaltMusic();
	}
	else {
		Mix_HaltChannel(-1);
	}
}
