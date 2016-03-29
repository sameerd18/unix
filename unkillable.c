#include <stdio.h>
#include <signal.h>

void endlessloop(int signum)
{
    signal(signum, endlessloop);
    printf("%d\n", signum);
    for(;;);
}

int main (void)
{
    for(int i=1; i<32; i++)
        signal(i, endlessloop);
    endlessloop(0);
}
