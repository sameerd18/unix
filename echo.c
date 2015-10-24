#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 1;
    if (i < argc)
        printf("%s", argv[i]);

    while (++i < argc)
        printf(" %s", argv[i]);

    printf("\n");
    return EXIT_SUCCESS;
}
