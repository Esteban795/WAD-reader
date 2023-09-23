SRCDIR = src
HEADDIR = include
LIBDIR = ./src

FLAGS = -lSDL2
DEBUGFLAGS = -W -Wall -Wextra -Wvla -fsanitize=address
DEPENDENCIES = $(SRCDIR)/byte_reader.c $(SRCDIR)/header.c

build:
	gcc $(SRCDIR)/wad_reader.c -o ./bin/wad_reader  $(DEPENDENCIES) $(FLAGS)

run:
	./bin/wad_reader

clean:
	rm ./bin/wad_reader

debug:
	gcc $(SRCDIR)/wad_reader.c -o ./bin/wad_reader $(DEPENDENCIES) $(DEBUGFLAGS) $(FLAGS)

all:
	make build
	make run