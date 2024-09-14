#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        fprintf(stdout, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }
    draw_tree(argv[1]);
    return 0;
}

void throw(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}