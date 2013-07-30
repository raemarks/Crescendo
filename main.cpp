#include "song.h"
#include "player.h"
#include "cresc_window.h"

int main (int argc, char *argv[]) {
	/*
	Player *p = new(Player);

	p->Play();
	cout << "Hello\n";
	SDL_Delay(6000);
	p->Pause();
	SDL_Delay(1000);
	p->Play();
	SDL_Delay(6000);
	*/
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	CrescWindow *w = new CrescWindow();
	
	w->Run();
	return 0;
}
