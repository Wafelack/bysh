#include <stdio.h>
#include <stdlib.h>

#include "build.h"

void buildhard(void)
{
    system("gcc src/*.c -o target/debug/debug.exe -W -Wall -Werror -Wextra");
}
void build(void)
{
    system("gcc src/*.c -o target/release/release.exe");
}
