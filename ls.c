#define _BSD_SOURCE

#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "proglib.h"

int strcmp_v(const void *s1, const void *s2)
{
    return strcmp(*(const char **) s1, *(const char **) s2);
}

int get_direntries(DIR *dir)
{
    int count = 0;
    for (struct dirent *entry; (entry = readdir(dir));)
        count++;
    seekdir(dir, 0);
    return count;
}

void print_dirlist(int count, char **dirlist)
{

    for (int i = 0; i < count; i++)
        printf("%s\n", dirlist[i]);
}

char** put_direntries(int count, char **dirlist, DIR *dir)
{
    for (int i = 0; i < count; i++) {
        struct dirent *entry = readdir(dir);
        if (!entry) {
            count = i;
            break;
        }
        dirlist[i] = entry->d_name;
    }
    return dirlist;
}

void lsdir(DIR *dir)
{
    char **dirlist = malloc(get_direntries(dir) * sizeof(char*));

    if (!dirlist)
        err(EXIT_FAILURE, NULL);

    dirlist = put_direntries(get_direntries(dir), dirlist, dir);
    qsort(dirlist, get_direntries(dir), sizeof(char *), strcmp_v);
    print_dirlist(get_direntries(dir), dirlist);
    free(dirlist);
}

void ls(char *dirname)
{
    DIR *dir = opendir(dirname);
    if (!dir)
        err(EXIT_FAILURE, NULL);

    lsdir(dir);
    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        ls(".");
    else if (argc == 2)
        ls(argv[1]);
    else {
        bool first = true;
        while (*++argv) {
            if (!first)
                printf("\n");
            printf("%s:\n", *argv);
            ls(*argv);
            first = false;
        }
    }
}
