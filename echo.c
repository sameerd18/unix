#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;
    if (i < argc)
        printf("%s", argv[i]);

    while (++i < argc)
        printf(" %s", argv[i]);

    printf("\n");
    return 0;
}
