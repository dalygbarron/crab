rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

OBJS = main.o Graphics.o Widget.o Map.o Generator.o Floor.o Wall.o Game.o Layer.o Move.o Mob.o Player.o Creature.o Vector.o Content.o
HEADERS := $(call rwildcard,src/,*.hh)
OBJ_NAME = main
CFLAGS = -std=c++14
LFLAGS = -lSDL2 -lSDL2_image
ADD =
SIZE = 64
CC = g++


bing.png: bing2.png
	cp bing2.png bing.png
	sips -Z $(SIZE) bing.png

%.o: src/%.cc $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(ADD)

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(OBJ_NAME) $(CFLAGS) $(ADD)

run: all bing.png
	./$(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME) $(OBJS) bing.png

count:
	git ls-files | xargs wc -l
