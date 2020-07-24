#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "../core/version.h"
#include "../core/new.h"
#include "../core/build.h"
#include "../core/run.h"
#include "../core/reinit.h"
#include "../core/header.h"

#include "../core/infos.h"

static bool exists(const char *fname);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage :\033[0;31m wmanager\033[0;36m <command>\033[1;33m [OPTIONS]\033[1;37m");
        return (EXIT_FAILURE);
    }
    if (strcmp(argv[1], "--version") == 0)
    {
        version(); //print current version
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "new") == 0 && argc == 3)
    {
        create(argv[2]); //initialize a new empty project
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "build") == 0)
    {
        if (argc == 3 && strcmp(argv[2], "--release") == 0)
        {
            build(); 
        }
        else
        {
            buildhard(); //mode with flags
        }
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "run") == 0)
    {
        run();
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "reinit") == 0)
    {
        if (!exists("lock.wmg")
            return EXIT_FAILURE;
        if (argc == 3)
        {
            if (strcmp(argv[2], "--force") == 0)
            {
                reinit();
                printf("\033[0;31mProject reinitialized !\033[1;37m\n");
                return EXIT_SUCCESS;
            }
        }
        char choice = 'N';
        printf("Really want to reinit ? Y/N : ");
        choice = getchar();
        choice = toupper(choice);
        if (choice == 'Y')
        {
            reinit();
            return EXIT_SUCCESS;
        }
        printf("\nAction aborted\n");
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "header") == 0 && argc == 3)
    {
        header(argv[2]);
        return EXIT_SUCCESS;
    }

    fprintf(stderr, "Usage :\033[0;31m wmanager\033[0;36m <command>\033[1;33m [OPTIONS]\033[1;37m");
    return (EXIT_FAILURE);
}
static bool exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return true;
    }
    return false;
}