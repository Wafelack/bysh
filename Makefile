CC = gcc
CFLAGS = -W -Wall -Werror -Wextra
OBJ = build/main.o build/version.o build/new.o build/build.o build/run.o build/reinit.o build/header.o

build : $(OBJ)
	gcc $(OBJ) -o wmanager

build/main.o : src/main.c
	$(CC) -o build/main.o -c src/main.c $(CFLAGS)

build/version.o : core/version.c
	$(CC) -o build/version.o -c core/version.c $(CFLAGS)

build/new.o : core/new.c
	$(CC) -o build/new.o -c core/new.c $(CFLAGS)

build/build.o : core/build.c
	$(CC) -o build/build.o -c core/build.c $(CFLAGS)

build/run.o : core/run.c
	$(CC) -o build/run.o -c core/run.c $(CFLAGS)

build/reinit.o : core/reinit.c
	$(CC) -o build/reinit.o -c core/reinit.c $(CFLAGS)

build/header.o : core/header.c
	$(CC) -o build/header.o -c core/header.c $(CFLAGS)