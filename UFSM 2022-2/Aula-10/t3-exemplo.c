#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial( int n )
{
if ( n <= 1 )
return 1;
else
return  n*fatorial(n-1);
}

double taylor_ex (int n_term, double value)
{
if (n_term <= 1)
return 1;
else
return taylor_ex(n_term-1, value) + pow(value, n_term-1)/fatorial(n_term-1);
}

int main()

{
double y;
y = taylor_ex(5, 2);
printf("taylor eh %g\n", y);
return 0;
}
