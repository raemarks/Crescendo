#include "label.h"

CrG_Label::CrG_Label(int x, int y, string text, TTF_Font *f) {
	r.x = x;
	r.y = y;
	font = f;
	color.r = 128;
	color.b = 54;
	SetText(text);
}

void CrG_Label::SetText(string text) {
	dispText = text;
	printf("set color.\n");
	rendered = TTF_RenderText_Solid(font, dispText.c_str(), color);
	if (!rendered) {
		printf("FAILED TO RENDER TEXT");
	}
	r.w = rendered->w;
	r.h = rendered->h;
}

void CrG_Label::Draw(SDL_Surface *surface) {
	SDL_BlitSurface(rendered, NULL, surface, &r);
}

