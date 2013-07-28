CC=g++
PROG_NAME=crescendo
SDL_FLAGS=`sdl-config --cflags --libs` -lSDL_mixer -lSDL_image -lSDL_ttf

all: player window button label
	$(CC) main.cpp song.cpp label.o button.o player.o window.o -o $(PROG_NAME) $(SDL_FLAGS)

player:
	$(CC) -c -o player.o player.cpp

window:
	$(CC) -c -o window.o cresc_window.cpp

button:
	$(CC) -c -o button.o gui/button.cpp

label:
	$(CC) -c -o label.o gui/label.cpp
