OBJS	= main.o samIO.o samBase.o
SOURCE	= main.c lib/samIO.c lib/samBase.c
HEADER	= main.h lib/samIO.h lib/samBase.c
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

doxygen: $(OBJS)
	doxygen Doxyfile

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
