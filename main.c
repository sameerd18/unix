#include "main.h"
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool hadErrors = false;

void runFile(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f) {
        run(f);
        fclose(f);
    }
    if (errno) {
        hadErrors = true;
        warn("%s", filename);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        run(stdin);
    else
        while (*++argv)
            runFile(*argv);
    return hadErrors ? EXIT_FAILURE : EXIT_SUCCESS;
}
