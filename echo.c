#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
        printf("%s", argv[1]);

    for (size_t i = 2; argc > i; i++)
        printf(" %s", argv[i]);

    printf("\n");
    return 0;
}
