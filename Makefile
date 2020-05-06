OBJS	= main.o samIO.o affichage.o jeuBase.o
SOURCE	= main.c lib/samIO.c src/affichage.c src/jeuBase.c
HEADER	= main.h lib/samIO.h src/affichage.h src/jeuBase.h
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

affichage.o: src/affichage.c
	$(CC) $(FLAGS) src/affichage.c

jeuBase.o:src/jeuBase.c
	$(CC) $(FLAGS) src/jeuBase.c

doxygen: $(OBJS)
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
