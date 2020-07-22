CC = gcc
CFLAGS = -W -Wall -Werror -Wextra
OBJ = bin/main.o bin/version.o bin/new.o bin/build.o bin/run.o bin/reinit.o bin/header.o

bin : $(OBJ)
	gcc $(OBJ) -o wanager

bin/main.o : src/main.c
	$(CC) -o bin/main.o -c src/main.c $(CFLAGS)

bin/version.o : core/version.c
	$(CC) -o bin/version.o -c core/version.c $(CFLAGS)

bin/new.o : core/new.c
	$(CC) -o bin/new.o -c core/new.c $(CFLAGS)

bin/build.o : core/build.c
	$(CC) -o bin/build.o -c core/build.c $(CFLAGS)

bin/run.o : core/run.c
	$(CC) -o bin/run.o -c core/run.c $(CFLAGS)

bin/reinit.o : core/reinit.c
	$(CC) -o bin/reinit.o -c core/reinit.c $(CFLAGS)

bin/header.o : core/header.c
	$(CC) -o bin/header.o -c core/header.c $(CFLAGS)