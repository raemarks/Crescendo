SDL_FLAGS=`sdl-config --cflags --libs` -lSDL_mixer

all: player
	g++ main.cpp song.cpp player.o -o song $(SDL_FLAGS)

player:
	g++ -c -o player.o player.cpp
