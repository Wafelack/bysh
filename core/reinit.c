#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#include "reinit.h"

static int exists(const char *fname);

void reinit(void)
{
    if (exists("lock.wmg") == 0)
        return;
    system("del /f /q src\\* ");
    RemoveDirectoryA("src");
    system("del /f /q  build\\*");
    system("del lock.wmg");
    RemoveDirectoryA("build");

    CreateDirectoryA("src", NULL);
    CreateDirectoryA("build", NULL);

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