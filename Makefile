OBJS = src/main.cc src/Graphics.cc src/Widget.cc src/Scene.cc

OBJ_NAME = main

all : $(OBJS)
	g++ $(OBJS) -W -lSDL2 -lSDL2_image -o $(OBJ_NAME) -std=c++11
