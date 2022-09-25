#include <stdio.h>
int a =0;
float multiplica(int d)
{
    a = d;
    return(a);
}

int main()
{
    int c;
    c = multiplica(2);
    printf("%d", c);
    return(0);
}
