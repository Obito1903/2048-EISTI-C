OBJS	= main.o samIO.o samBase.o jeuBase.o affichageTerm.o gestionAffichage.o
SOURCE	= main.c lib/samIO.c lib/samBase.c src/jeuBase.c src/affichageTerm.c src/gestionAffichage.c
HEADER	= main.h lib/samIO.h lib/samBase.c src/jeuBase.h src/affichageTerm.h src/gestionAffichage.h
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

jeuBase.o:src/jeuBase.c
	$(CC) $(FLAGS) src/jeuBase.c

affichageTerm.o: src/affichageTerm.c
	$(CC) $(FLAGS) src/affichageTerm.c

gestionAffichage.o: src/gestionAffichage.c
	$(CC) $(FLAGS) src/gestionAffichage.c

doxygen: $(OBJS)
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
