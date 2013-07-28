#include "button.h"

CrG_Button::CrG_Button(int loc_x, int loc_y, int siz_x, int siz_y) {
	r.x = loc_x;
	r.y = loc_y;
	r.w = siz_x;
	r.h = siz_y;
	disp = NULL;
	toggled = false;
}

CrG_Button::~CrG_Button() {
	if (disp) {
		SDL_FreeSurface(disp);
	}
	if (alt) {
		SDL_FreeSurface(alt);
	}
}

bool CrG_Button::WasClicked(int x, int y) {
	return (x >= r.x && x < r.x + r.w) && (y >= r.y && y < r.y + r.h);
}

void CrG_Button::Draw(SDL_Surface *surface) {
	SDL_Surface *toDraw = toggled ? alt : disp;
	if (SDL_BlitSurface(toDraw, NULL, surface, &r)) {
		fprintf(stderr, "An error occured during blitting.\n");
	}
}

int CrG_Button::SetImage(string imgpath) {
	//Load image, set as disp
	disp = IMG_Load(imgpath.c_str());
	if (disp == NULL) {
		fprintf(stderr, "An error occcured while loading the image.\n");
		return -1;
	}
	return 0;
}

int CrG_Button::SetAlt(string imgpath) {
	//Load image, set as disp
	alt = IMG_Load(imgpath.c_str());
	if (alt == NULL) {
		fprintf(stderr, "An error occcured while loading the image.\n");
		return -1;
	}
	return 0;
}

bool CrG_Button::Toggle() {
	return (toggled = !toggled);
}
