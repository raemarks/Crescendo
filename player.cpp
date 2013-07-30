#include "player.h"

Player *activePlayer = NULL;

Player::Player() {

	//Should be configurable
	int audio_rate = 44100;
	Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
	int audio_channels = 2;
	int audio_buffers = 4096;
	//


	//Start up sound card
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
		fprintf(stderr,"Unable to open audio: %s\n", SDL_GetError());
		exit(1);
	}

	MusicPaused = false;
	activePlayer = this;
}

Player::~Player() {
	//Ensure all songs have been properly deallocated
}

void Player::Play() {
	if (MusicPaused) {
		Mix_ResumeMusic();
		MusicPaused = false;
	} else {
		//Get first song to play

		//TEMP: just grab test song
		current = Mix_LoadMUS("song.flac");
		next = Mix_LoadMUS("next.flac");
		if (!current) {
			fprintf(stderr, "Error opening music file: %s\n", SDL_GetError());
			exit(1);
		}

		playCurrent();
	}
}

void Player::playCurrent() {
	Mix_PlayMusic(current, 0);
	Mix_HookMusicFinished(SongFinishedCallback);
}

void Player::SongFinished() {
	fprintf(stderr, "Song finished!\n");
	Mix_Music *last = current;
	if (next != NULL) {
		current = next;
		playCurrent();
	}

	Mix_FreeMusic(last);
	LoadNext();
}

void Player::Pause() {
	if (!MusicPaused) {
		Mix_PauseMusic();
		MusicPaused = true;
	}
}

void Player::LoadNext() {
	next = Mix_LoadMUS("next.flac");
	if (!next) {
		fprintf(stderr, "Error opening music file: %s\n", SDL_GetError());
	}
}

void SongFinishedCallback() {
	activePlayer->SongFinished();
}
