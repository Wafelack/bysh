#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "new.h"

void create(char *name)
{
    CreateDirectoryA(name, NULL);
    printf("\033[0;32m Succesfuly\033[1;37m created empty project in\033[0;31m %s/\033[1;37m", name);
}