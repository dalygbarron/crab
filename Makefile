rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

OBJS = main.o Graphics.o Widget.o Scene.o Map.o Generator.o Floor.o Wall.o Observer.o Input.o Game.o Layer.o
HEADERS := $(call rwildcard,src/,*.hh)
OBJ_NAME = main
CFLAGS = -std=c++14
LFLAGS = -lSDL2 -lSDL2_image
CC = g++



%.o: src/%.cc $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) -g

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OBJ_NAME) $(CFLAGS) -g

run: all
	./$(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME) $(OBJS)

count:
	git ls-files | xargs wc -l
