#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "new.h"

void create(char *name)
{
    char *commande = malloc((strlen(name) * sizeof(char) + (6 * sizeof(char))));
    sprintf(commande, "mkdir %s", name);
    system(commande);
    printf("\033[0;32m Succesfuly\033[1;37m created empty project in\033[0;31m %s/\033[1;37m", name);
    free(commande);
}