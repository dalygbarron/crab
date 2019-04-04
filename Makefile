OBJS = src/main.cc src/Graphics.cc src/Widget.cc src/Scene.cc src/Map.cc src/Generator.cc

OBJ_NAME = main

all: $(OBJS)
	g++ $(OBJS) -lSDL2 -lSDL2_image -o $(OBJ_NAME) -std=c++14
