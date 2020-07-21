CC = gcc
CFLAGS = -W -Wall -Werror -Wextra
OBJ = build/main.o build/version.o build/new.o

build : $(OBJ)
	gcc $(OBJ) -o wmanager

build/main.o : src/main.c
	$(CC) -o build/main.o -c src/main.c $(CFLAGS)

build/version.o : core/version.c
	$(CC) -o build/version.o -c core/version.c $(CFLAGS)

build/new.o : core/new.c
	$(CC) -o build/new.o -c core/new.c $(CFLAGS)