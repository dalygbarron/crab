OBJS = src/main.cc src/Graphics.cc src/Widget.cc src/Scene.cc src/Map.cc src/Generator.cc \
	src/Floor.cc src/Wall.cc

OBJ_NAME = main

src/font.h: bing.png
	rm src/font.h
	echo "#ifndef FONT_H\n#define FONT_H\n" >> src/font.h
	convert bing.png -alpha extract tmp
	cat tmp >> src/font.h
	rm tmp
	echo "\n#endif" >> src/font.h


all: $(OBJS)
	g++ $(OBJS) -lSDL2 -lSDL2_image -o $(OBJ_NAME) -std=c++14
