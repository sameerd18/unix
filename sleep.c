#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>


int atoi_e(char *nstr)
{
    char *endptr;

    errno = 0;
    int retval = strtol(nstr, &endptr, 0);

    if (errno == 0 && *endptr != '\0')
        errno = EINVAL;
    if (errno != 0)
        err(EXIT_FAILURE, "%s", nstr);

    return retval;
}

char *get_progname(char *progname)
{
    char *slash = rindex(progname, '/');
    if (slash != NULL)
        progname = slash + 1;
    return progname;
}

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
