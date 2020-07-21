#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "run.h"

static int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void run(void)
{
    if (exists("build/main.exe"))
    {
        system("build\\main.exe");
    }
    else
    {
        fprintf(stderr, "\033[0;31mError\033[1;37m : File\033[0;34m main.exe\033[0;31m does not exists\n\n\033[1;37mRun \"wmanager build\" to build your project\n");
    }
}