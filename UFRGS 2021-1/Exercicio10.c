/*
Nesse c�digo eu realizei os teste para responder uma quest�o de for com fatorial.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, k;
    n = 5;
    for (i = n-1 ; i>=1; i--)
    {
        n = i * n;
    }
    printf("%d", n);
    return(0);
}
/* EST� PRONTO*/
