OBJS = src/main.cc src/Graphics.cc src/scenes/Title.cc

OBJ_NAME = main

all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -o $(OBJ_NAME)
