#include <stdio.h>

#include "greet.h"
#include "target.h"

int main(void)
{
    greet();
    printf(", ");
    target();
    printf("!\n");
    return 0;
}

