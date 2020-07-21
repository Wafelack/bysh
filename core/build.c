#include <stdio.h>
#include <stdlib.h>

#include "build.h"

void buildhard(void)
{
    system("gcc src/*.c -o build/main -W -Wall -Werror -Wextra");
}
void build(void)
{
    system("gcc src/*.c -o build/main");
}
