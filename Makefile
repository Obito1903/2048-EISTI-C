OBJS	= main.o samIO.o samBase.o init2048.o affichageSDL.o deplacement.o jeu2048.o
SOURCE	= main.c lib/samIO.c lib/samBase.c src/init2048.c src/affichageSDL.c src/deplacement.c src/jeu2048.c
HEADER	= main.h lib/samIO.h lib/samBase.h src/init2048.h src/affichageSDL.h src/deplacement.h src/jeu2048.h
OUT	= projet
CC	 = gcc
SDLFLAGS=`sdl2-config --cflags --libs`
FLAGS	 = -g -c -Wall -Wextra -pedantic
LFLAGS	 = -Llib -lm
IFLAGS	 = -Iinclude

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) $(SDLFLAGS)

main.o: main.c
	$(CC) $(FLAGS) $(IFLAGS) main.c

samIO.o: lib/samIO.c
	$(CC) $(FLAGS) $(IFLAGS) lib/samIO.c

samBase.o: lib/samBase.c
	$(CC) $(FLAGS) $(IFLAGS) lib/samBase.c

init2048.o: src/init2048.c
	$(CC) $(FLAGS) $(IFLAGS) src/init2048.c

affichageSDL.o: src/affichageSDL.c
	$(CC) $(FLAGS) $(IFLAGS) src/affichageSDL.c

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
