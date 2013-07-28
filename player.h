#ifndef CRESCENDO_PLAYER
#define CRESCENDO_PLAYER

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

using std::cout;
using std::string;

class Player
{
public:
	Player();
	~Player();

	void Play();
	void Pause();
	void Next();
	void Previous();

	void Load(string configfile);
	void Save(string configfile);
private:
	//MusicList
	Mix_Music *current;
	Mix_Music *next;

	bool MusicPaused;
};

#endif
