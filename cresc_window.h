#ifndef CRESC_WINDOW_H
#define CRESC_WINDOW_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include "gui/button.h"
#include "gui/label.h"
#include "player.h"

using std::string;

class CrescWindow
{
public:
	CrescWindow();
	~CrescWindow();

	int Run();


private:
	void handleEvents();
	void handleKey();
	void handleClick();
	void draw();

	Player *player;
	int x;
	int y;

	bool running;

	SDL_Event event;
	SDL_Surface *screen;
	TTF_Font *font;

	string configDir;

	//Screen objects
	CrG_Button *playButton;
	CrG_Button *nextButton;
	CrG_Button *prevButton;

	CrG_Label *nowPlaying;
};

#endif
