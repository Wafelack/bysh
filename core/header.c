#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

void header(char *name)
{
    char *def = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 13));
    char *ifn = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 13));
    char *end = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 16));
    char *full = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 3));
    char *NAME = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 3));
    char *wext = malloc((strlen(name) * sizeof(char)) + (sizeof(char) * 2));
    for (unsigned int i = 0; i < strlen(name); i++)
    {
        NAME[i] = toupper(name[i]);
        printf("[%c]", NAME[i]);
    }

    sprintf(full, "_%s_H_", NAME);
    sprintf(wext, "%s.h", name);
    sprintf(def, "#define %s\n", full);
    sprintf(ifn, "#ifndef %s\n", full);
    sprintf(end, "#endif /*%s*/\n", full);

    FILE *fic = fopen(wext, "w+");
    if (fic == NULL)
    {
        return;
    }
    fputs(ifn, fic);
    fputs(def, fic);
    fputs("\n\n\n", fic);
    fputs(end, fic);
    fclose(fic);
    free(def);
    free(ifn);
    free(end);
    free(full);
    free(NAME);
    free(wext);
}