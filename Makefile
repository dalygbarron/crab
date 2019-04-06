rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

OBJS = main.o Graphics.o Widget.o Scene.o Map.o Generator.o Floor.o Wall.o
HEADERS := $(call rwildcard,src/,*.hh)
OBJ_NAME = main
CFLAGS = -std=c++14
LFLAGS = -lSDL2 -lSDL2_image
CC = g++



%.o: src/%.cc $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OBJ_NAME) -std=c++14

run: all
	./$(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME) $(OBJS)
