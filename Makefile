OBJS	= main.o samIO.o affichageTerm.o gestionAffichage.o jeuBase.o
SOURCE	= main.c lib/samIO.c src/affichageTerm.c src/gestionAffichage.c src/jeuBase.c
HEADER	= main.h lib/samIO.h src/affichageTerm.h src/gestionAffichage.h src/jeuBase.h
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

affichageTerm.o: src/affichageTerm.c
	$(CC) $(FLAGS) src/affichageTerm.c

gestionAffichage.o: src/gestionAffichage.c
	$(CC) $(FLAGS) src/gestionAffichage.c

jeuBase.o:src/jeuBase.c
	$(CC) $(FLAGS) src/jeuBase.c

doxygen: $(OBJS)
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
