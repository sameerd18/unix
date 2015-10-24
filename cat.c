#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool hadErrors = false;

void cat(FILE *f)
{
    for (int c; (c = getc(f)) != EOF;)
        putchar(c);
}

void catFile(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f) {
        cat(f);
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
        cat(stdin);
    else
        while (*++argv)
            catFile(*argv);
    return hadErrors ? EXIT_FAILURE : EXIT_SUCCESS;
}
