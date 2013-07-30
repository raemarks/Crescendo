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

	void LoadNext();

	void SongFinished();

	void Load(string configfile);
	void Save(string configfile);
private:
	void playCurrent();

	//MusicList
	Mix_Music *current;
	Mix_Music *next;

	bool MusicPaused;
};

//This is a mild hack, but callbacks are ugly in most languages anyways.
void SongFinishedCallback();

#endif
