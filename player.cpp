#include "player.h"

Player::Player() {

	//Should be configurable
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
	int audio_channels = 2;
	int audio_buffers = 4096;
	//


	//Start up sound card
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
		cout << "Unable to open audio!\n";
		exit(1);
	}

	MusicPaused = false;
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
		if (!current) {
			fprintf(stderr, "Error opening music file: %s\n", SDL_GetError());
			exit(1);
		}

		Mix_PlayMusic(current, 0);
	}
}

void Player::Pause() {
	if (!MusicPaused) {
		Mix_PauseMusic();
		MusicPaused = true;
	}
}
