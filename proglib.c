#include "proglib.h"
#include <err.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>

int atoi_e(char *nstr)
{
    char *endptr;

    errno = 0;
    int retval = strtol(nstr, &endptr, 10);

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
