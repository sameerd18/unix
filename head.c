#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool hadErrors = false;

void head(FILE *f)
{
    for (int c, lineNumber = 0; (lineNumber < 10) && ((c = getc(f)) != EOF);) {
        putchar(c);
        if (c == '\n')
            lineNumber++;
    }
}

void headFile(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f) {
        head(f);
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
        head(stdin);
    else
        while (*++argv)
            headFile(*argv);
    return hadErrors ? EXIT_FAILURE : EXIT_SUCCESS;
}
