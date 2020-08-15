#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "new.h"

char *customPath(char *base, const char *adding);

void create(char *name)
{
    CreateDirectoryA(name, NULL);

    char *src = customPath(name,"/src");
    char *build = customPath(name,"/target");
    char *debug = customPath(name, "/target/debug");
    char *release = customPath(name, "/target/release");
    char *file = customPath(name, "/src/main.c");
    char *locker = customPath(name, "/lock.wmg");

    CreateDirectoryA(src, NULL);
    CreateDirectoryA(build, NULL);

    CreateDirectoryA(debug, NULL);
    CreateDirectoryA(release, NULL);

    FILE *fic = fopen(file, "w+");
    if (fic == NULL)
    {
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
    free(debug);
    free(release);

    printf("\033[0;32m Succesfuly\033[1;37m\033[0m initialized project\033[1m %s\033[0m in\033[0;31m %s/\033[1;37m", name, name);
}
char *customPath(char *base, const char *adding)
{
    char *output = malloc(strlen(base) + strlen(adding));
    sprintf(output, "%s%s", base, adding);
    return output;
}