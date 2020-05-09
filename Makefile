OBJS	= main.o samIO.o samBase.o init2048.o affichage.o deplacement.o jeu2048.o
SOURCE	= main.c lib/samIO.c lib/samBase.c src/init2048.c src/affichage.c src/deplacement.c src/jeu2048.c
HEADER	= main.h lib/samIO.h lib/samBase.h src/init2048.h src/affichage.h src/deplacement.h src/jeu2048.h
OUT	= projet
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -pedantic
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c

samIO.o: lib/samIO.c
	$(CC) $(FLAGS) lib/samIO.c

samBase.o: lib/samBase.c
	$(CC) $(FLAGS) lib/samBase.c

init2048.o: src/init2048.c
	$(CC) $(FLAGS) src/init2048.c

affichage.o: src/affichage.c
	$(CC) $(FLAGS) src/affichage.c

deplacement.o: src/deplacement.c
	$(CC) $(FLAGS) src/deplacement.c

jeu2048.o: src/jeu2048.c
	$(CC) $(FLAGS) src/jeu2048.c

doxygen: $(OBJS)
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
