#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "new.h"

void create(char *name)
{
    char *src = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 4));
    sprintf(src, "%s/src", name);

    char *build = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 5));
    sprintf(build, "%s/build", name);

    char *file = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 11));
    sprintf(file, "%s/src/main.c", name);

    char *locker = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 9));
    sprintf(locker, "%s/lock.wmg", name);

    CreateDirectoryA(name, NULL);
    CreateDirectoryA(src, NULL);
    CreateDirectoryA(build, NULL);

    FILE *fic = fopen(file, "w+");
    if (fic == NULL)
    {
        fprintf(stderr, "Erreur:\tle fichier ne s'est pas ouvert correctement\n");
        return;
    }
    fputs("#include <stdio.h>\n\n", fic);
    fputs("int main(void) {\n", fic);
    fputs("    printf(\"Hello World\");\n", fic);
    fputs("    return 0;\n", fic);
    fputs("}\n", fic);
    fclose(fic);

    FILE *lock = fopen(locker, "w+");
    if (lock == NULL)
    {
        fprintf(stderr, "Erreur:\tle fichier ne s'est pas ouvert correctement\n");
        return;
    }
    fputs("DONT DELETE IMPORTANT FILE", lock);
    fclose(lock);

    free(src);
    free(build);
    free(file);
    free(locker);

    printf("\033[0;32m Succesfuly\033[1;37m\033[0m initialized project\033[1m %s\033[0m in\033[0;31m %s/\033[1;37m", name, name);
}