#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a [11][11] = {0}, b [11]={0};
    int j, i;
    a[6][6] = b[j];
    for(i = 0; i<11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            if (i == j)
            {
                a[i][j]= i+j;
            }
            else
                a[i][j] = 0;
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    return(0);
}
