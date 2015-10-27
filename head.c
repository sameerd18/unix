#include "main.h"
#include <stdio.h>

void head(FILE *f)
{
    for (int c, lineNumber = 0; (lineNumber < 10) && ((c = getc(f)) != EOF);) {
        putchar(c);
        if (c == '\n')
            lineNumber++;
    }
}

void (*run)(FILE *) = head;
