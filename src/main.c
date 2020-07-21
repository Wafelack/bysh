#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../core/version.h"
#include "../core/new.h"
#include "../core/build.h"
#include "../core/run.h"

#include "../core/infos.h"

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
        if (argc == 3 && strcmp(argv[2], "--hard") == 0)
        {
            buildhard(); //mode with flags
        }
        else
        {
            build();
        }
        return EXIT_SUCCESS;
    }
    if (strcmp(argv[1], "run") == 0)
    {
        run();
        return EXIT_SUCCESS;
    }

    fprintf(stderr, "Usage :\033[0;31m wmanager\033[0;36m <command>\033[1;33m [OPTIONS]\033[1;37m");
    return (EXIT_FAILURE);
}