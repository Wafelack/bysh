#include <stdio.h>
#include <stdlib.h>

#include "build.h"

void buildhard(void)
{
    system("gcc src/*.c -o build/main -W -Wall -Werror -Wextra");
    fprintf(stderr, "\033[0;32mProject built successfully !\033[1;37m\n");
}
void build(void)
{
    system("gcc src/*.c -o build/main");
}
