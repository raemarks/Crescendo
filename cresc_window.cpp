#include "cresc_window.h"

CrescWindow::CrescWindow() {
	x = 400;
	y = 400;

	screen = SDL_SetVideoMode(x,y,0,0);
	font = TTF_OpenFont("FAMI_E.TTF",18);
	if (!font) {
		fprintf(stderr, "Font failed to load: %s\n", SDL_GetError());
	}

	player = new Player();

	if (initGraphics()) {
		fprintf(stderr, "Error initializing gui elements.\n");
		exit(1);
	}
}

int CrescWindow::initGraphics() {
	playButton = new CrG_Button(10,10,48,48);
	playButton->SetImage("img/play.bmp");
	playButton->SetAlt("img/pause.bmp");

	nowPlaying = new CrG_Label(10,60,"Hello World!", font);

	return 0;
}

CrescWindow::~CrescWindow() {
	TTF_CloseFont(font);
	SDL_FreeSurface(screen);
}

int CrescWindow::Run() {
	running = true;

	while (running) {
		handleEvents();

		draw();

		SDL_Delay(50); //dont hog that cpu
	}

	return 0;
}

void CrescWindow::handleEvents() {
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYUP:
				handleKey();
			case SDL_KEYDOWN:
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			case SDL_MOUSEBUTTONDOWN:
				handleClick();
			case SDL_MOUSEMOTION:
				break;
		}
	}
}

void CrescWindow::handleKey() {
	switch (event.key.keysym.scancode) {
		case SDLK_SPACE:
			if(playButton->Toggle()) {
				player->Play();
			} else {
				player->Pause();
			}
			break;
	}
}

void CrescWindow::handleClick() {
	if (playButton->WasClicked(event.button.x, event.button.y)) {
		//Click button
		if(playButton->Toggle()) {
			player->Play();
		} else {
			player->Pause();
		}
	}
}

void CrescWindow::draw() {
	playButton->Draw(screen);
	nowPlaying->Draw(screen);
	SDL_Flip(screen);
}
