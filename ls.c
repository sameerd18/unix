#define _BSD_SOURCE

#include <err.h>
#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "proglib.h"

int strcmp_v(const void *s1, const void *s2)
{
    return strcmp(*(const char **) s1, *(const char **) s2);
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    int count=0;

    argc = argc;

    dir = opendir(argv[1]);

    if (dir != NULL)
    {
	    entry = readdir(dir);
	    while(entry != NULL)
	    {
		    entry = readdir(dir);
		    count++;
	    }
	    seekdir(dir, 0);

	    char **dirlist = malloc(count * sizeof(char*));

	    for(int i=0; i < count; i++)
	    {
		    entry = readdir(dir);
		    dirlist[i] = entry->d_name;
	    }

	    qsort(dirlist, count, sizeof(char *), strcmp_v);

	    for (int i=0; i < count; i++)
		    printf("%s\n", dirlist[i]);

	    closedir(dir);
    }
    else
    {
	fprintf(stderr, "invalid directory");
	exit(EXIT_FAILURE);
    }
}

