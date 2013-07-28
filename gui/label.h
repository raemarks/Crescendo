#ifndef CRESC_GUI_LABEL_H
#define CRESC_GUI_LABEL_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

using std::string;

class CrG_Label
{
public:
	CrG_Label(int x, int y, string text, TTF_Font *f);
	void Draw(SDL_Surface *surface);
	void SetText(string text);
	void SetFont(TTF_Font *f);
private:
	string dispText;
	SDL_Surface *rendered;
	TTF_Font *font;
	SDL_Color color;
	SDL_Rect r;
};

#endif
