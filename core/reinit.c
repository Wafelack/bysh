#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

#include "reinit.h"

static bool exists(const char *fname);

void reinit(void)
{
    if (!exists("lock.wmg"))
        return;
    system("del /f /q src\\* ");
    RemoveDirectoryA("src");
    system("del /f /q  target\\*");

    system("del lock.wmg");
    RemoveDirectoryA("target");

    CreateDirectoryA("src", NULL);
    CreateDirectoryA("target", NULL);
    CreateDirectoryA("target\\debug", NULL);
    CreateDirectoryA("target\\release", NULL);

    FILE *fic = fopen("src\\main.c", "w+");
    fputs("#include <stdio.h>\n\n", fic);
    fputs("int main(void) {\n", fic);
    fputs("    printf(\"Hello World\");\n", fic);
    fputs("    return 0;\n", fic);
    fputs("}\n", fic);
    fclose(fic);

    FILE *lock = fopen("lock.wmg", "w+");
    if (lock == NULL)
    {
        fprintf(stderr, "Erreur:\tle fichier ne s'est pas ouvert correctement\n");
        return;
    }
    fputs("DONT DELETE IMPORTANT FILE", lock);
    fclose(lock);
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