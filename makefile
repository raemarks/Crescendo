CC=g++
PROG_NAME=crescendo
SDL_FLAGS=`sdl-config --cflags --libs` -lSDL_mixer -lSDL_image -lSDL_ttf
OBJ_DIR := obj

SOURCE_FILES := main.cpp \
	song.cpp \
	label.cpp \
	button.cpp \
	player.cpp \
	cresc_window.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCE_FILES:.cpp=.o))

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROG_NAME) $(SDL_FLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@if [ ! -d $(OBJ_DIR) ] ; then mkdir -p $(OBJ_DIR); fi
	$(CC) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(PROG_NAME)
