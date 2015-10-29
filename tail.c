#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE_FOR_NUL_BYTE 1
#define ONE_FOR_NEW_CHARACTER 1

void expand(char **currentLine)
{
    if (*currentLine == NULL) {
        *currentLine = malloc(ONE_FOR_NUL_BYTE);
        **currentLine = '\0';
    }
    size_t lineLength = strlen(*currentLine);
    *currentLine = realloc(*currentLine, lineLength + ONE_FOR_NUL_BYTE + ONE_FOR_NEW_CHARACTER);
}

void append(char **currentLine, char c)
{
    size_t lineLength = strlen(*currentLine);
    (*currentLine)[lineLength] = c;
    (*currentLine)[lineLength + ONE_FOR_NUL_BYTE] = '\0';
}

void expandAndAppend(char **currentLine, char c)
{
    expand(currentLine);
    append(currentLine, c);
}

void printAndFreeLineIfNotNull(char **lineToPrint)
{
    if (*lineToPrint != NULL) {
        printf("%s", *lineToPrint);
        free(*lineToPrint);
        *lineToPrint = NULL;
    }
}

bool isNewline(int c)
{
    return c == '\n';
}

void tail(FILE *file)
{
    int lineNumber = 0;
    char *lineBuffer[11];
    char **currentLine = &lineBuffer[0];
    memset(lineBuffer, 0, sizeof(lineBuffer));

    for (int c; (c = getc(file)) != EOF;) {
        expandAndAppend(currentLine, c);

        if (isNewline(c)) {
            lineNumber++;
            currentLine = &lineBuffer[lineNumber % 11];
            free(*currentLine);
            *currentLine = NULL;
        }
    }
    for (int i = 0; i < 11; i++)
        printAndFreeLineIfNotNull(&lineBuffer[(i + lineNumber) % 11]);
}

void (*run)(FILE *) = tail;
