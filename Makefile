CC = gcc
CFLAGS = -W -Wall -Werror -Wextra
OBJ = build/main.o

build : $(OBJ)
	gcc $(OBJ) -o wmanager

build/main.o : src/main.c
	$(CC) -o build/main.o -c src/main.c $(CFLAGS)