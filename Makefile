OBJS = src/main.cc src/Graphics.cc

OBJ_NAME = main

all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
