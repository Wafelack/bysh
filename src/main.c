#include <stdio.h>
#include <stdlib.h>

#define VERSION "Alpha-0.1.0"

int main(int argc, char **argv)
{
    if (argc < 2)
        printf("Wafelack | wmanager - version %s\n\nGitHub : https://github.com/Wafelack/wmanager\n%s", VERSION, argv[0]);
}