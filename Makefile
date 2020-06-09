OBJS	= main.o samIO.o samBase.o init2048.o affichageSDL.o textureManager.o renderSDL.o evenementSDL.o deplacement.o jeu2048.o
SOURCE	= main.c lib/samIO.c lib/samBase.c src/init2048.c src/affichage/affichageSDL.c src/affichage/textureManager.c src/affichage/renderSDL.c src/affichage/evenementSDL.c src/deplacement.c src/jeu2048.c
HEADER	= main.h lib/samIO.h lib/samBase.h src/init2048.h src/affichage/affichageSDL.h src/affichage/textureManager.h src/affichage/renderSDL.h src/affichage/evenementSDL.h src/deplacement.h src/jeu2048.h
OUT	= bin/projet
CC	 = gcc
SDLFLAGS=`sdl2-config --cflags --libs`
FLAGS	 = -g -c -Wall -Wextra -pedantic
LFLAGS	 = -Llib -lm -lSDL2_ttf -lSDL2_image
LFLAGSWIN	 = -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lm
IFLAGS	 = -Iinclude

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) $(SDLFLAGS)

win: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGSWIN)

main.o: main.c
	$(CC) $(FLAGS) $(IFLAGS) main.c

samIO.o: lib/samIO.c
	$(CC) $(FLAGS) $(IFLAGS) lib/samIO.c

samBase.o: lib/samBase.c
	$(CC) $(FLAGS) $(IFLAGS) lib/samBase.c

init2048.o: src/init2048.c
	$(CC) $(FLAGS) $(IFLAGS) src/init2048.c

affichageSDL.o: src/affichage/affichageSDL.c
	$(CC) $(FLAGS) $(IFLAGS) src/affichage/affichageSDL.c

textureManager.o: src/affichage/textureManager.c
	$(CC) $(FLAGS) $(IFLAGS) src/affichage/textureManager.c

renderSDL.o: src/affichage/renderSDL.c
	$(CC) $(FLAGS) $(IFLAGS) src/affichage/renderSDL.c

evenementSDL.o: src/affichage/evenementSDL.c
	$(CC) $(FLAGS) $(IFLAGS) src/affichage/evenementSDL.c

deplacement.o: src/deplacement.c
	$(CC) $(FLAGS) $(IFLAGS) src/deplacement.c

jeu2048.o: src/jeu2048.c
	$(CC) $(FLAGS) $(IFLAGS) src/jeu2048.c

doxygen:
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
