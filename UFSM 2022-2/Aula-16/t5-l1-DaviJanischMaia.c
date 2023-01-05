#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    for(int i = 0; i < 10; i++){
        printf("\n%d", rand() % 10);
    }

    return 0;
}
