#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "proglib.h"


void validate_progargs(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "%s: missing operand\n", get_progname(argv[0]));
        exit(EXIT_FAILURE);
    }
    if (argc > 2) {
        errno = E2BIG;
        err(EXIT_FAILURE, NULL);
    }
}

int main(int argc, char* argv[])
{
    validate_progargs(argc, argv);
    int sleepval = atoi_e(argv[1]);
    sleep(sleepval);
}
