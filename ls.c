#define _BSD_SOURCE

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


int strcmp_v(const void *s1, const void *s2)
{
    return strcmp(*(const char **) s1, *(const char **) s2);
}

int main(void)
{
    DIR *dir;
    struct dirent *entry;
    int count=0;

    dir = opendir(".");
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

