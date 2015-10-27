#include "main.h"
#include <stdio.h>

void cat(FILE *f)
{
    for (int c; (c = getc(f)) != EOF;)
        putchar(c);
}

void (*run)(FILE *) = cat;
