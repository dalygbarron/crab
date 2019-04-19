rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SQL_FOLDER = src/sql
SQL_HEADER = src/Queries.gen.hh
SQL_FILE = src/Queries.gen.cc
OBJS = main.o Graphics.o Widget.o Map.o Generator.o Floor.o Wall.o Game.o Layer.o Move.o Mob.o Player.o Creature.o \
	Vector.o Content.o Repository.o $(SQL_FILE)
HEADERS := $(call rwildcard,src/,*.hh)
OBJ_NAME = main
JUNK = $(OBJS) $(SQL_HEADER) $(SQL_FILE) $(OBJ_NAME) bing.png sqlite3.o
CFLAGS = -std=c++14
LFLAGS = -lSDL2 -lSDL2_image -lpthread -ldl
ADD =
SIZE = 64
CC = g++

bing.png: bing2.png
	cp bing2.png bing.png
	#sips -Z $(SIZE) bing.png

sqlite3.o: src/sqlite3.c
	gcc -c -o sqlite3.o src/sqlite3.c $(ADD)

$(SQL_HEADER): $(SQL_FOLDER)/*.sql
	echo "#ifndef QUERIES_H" > $(SQL_HEADER)
	echo "#define QUERIES_H" >> $(SQL_HEADER)
	echo "namespace Queries {" >> $(SQL_HEADER)
	@for f in $(notdir $(basename $(wildcard $(SQL_FOLDER)/*.sql))); do \
		echo "extern const char *$${f};" >> $(SQL_HEADER); \
	done
	echo "};" >> $(SQL_HEADER)
	echo "#endif" >> $(SQL_HEADER)

$(SQL_FILE): $(SQL_FOLDER)/*.sql
	echo "#include \"Queries.gen.hh\"" > $(SQL_FILE)
	@for f in $(notdir $(basename $(wildcard $(SQL_FOLDER)/*.sql))); do \
		echo "const char *Queries::$${f} = R\"(" >> $(SQL_FILE); \
		cat $(SQL_FOLDER)/$${f}.sql >> $(SQL_FILE); \
		echo ")\";" >> $(SQL_FILE); \
	done

%.o: src/%.cc $(HEADERS) $(SQL_HEADER)
	$(CC) -c -o $@ $< $(CFLAGS) $(ADD)

all: $(OBJS) sqlite3.o bing.png
	$(CC) $(OBJS) sqlite3.o $(LFLAGS) -o $(OBJ_NAME) $(CFLAGS) $(ADD)

run: all
	./$(OBJ_NAME)

clean:
	rm -f $(JUNK)

count:
	git ls-files *[^.cc] | xargs wc -l
