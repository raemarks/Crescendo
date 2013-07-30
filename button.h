#ifndef CRESC_GUI_BUTTON_H
#define CRESC_GUI_BUTTON_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

using std::string;

class CrG_Button
{
public:
	CrG_Button(int loc_x, int loc_y, int siz_x, int siz_y);
	~CrG_Button();
	
	bool WasClicked(int x, int y);
	void Draw(SDL_Surface *surface);
	int SetImage(string imgpath);
	int SetAlt(string imgpath);
	bool Toggle();

private:
	SDL_Surface *disp;
	SDL_Surface *alt;

	SDL_Rect r;

	bool toggled;
};

#endif
