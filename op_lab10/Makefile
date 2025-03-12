CC = gcc
CFLAGS = -Wall -std=c11
OBJ = main.o list.o read_write.o

all: program

program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ)

main.o: main.c books.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c books.h
	$(CC) $(CFLAGS) -c list.c

read_write.o: read_write.c books.h
	$(CC) $(CFLAGS) -c read_write.c

