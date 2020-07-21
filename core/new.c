#include <stdio.h>
#include <stdlib.h>

#include "new.h"

#define PATH_TO_CREATOR "C:\\Users\\wafelack\\Documents\\c\\wmanager\\core\\creator.bat"

void create(char *name)
{
    char *chdir = "";
    char *create = "";

    sprintf(chdir, "cd %s", name);

    sprintf(create, "%s %s", PATH_TO_CREATOR, name);

    system(chdir);
    system("git init");

    system("cd ..");

    printf("\033[0;32m Succesfully created a new project\033[1;37m in\033[0;31m %s/\033[1;37m and initialized a git repository", name);
}