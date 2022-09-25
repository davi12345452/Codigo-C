#include <stdio.h>
#include <conio2.h>

#define XINI 1
#define XFIM 79
#define YINI 1
#define YFIM 24

int main (void)
{
    int i;
    clrscr();
    gotoxy( 1, 1 );
    for (i = 1; i <= XFIM; i++) putch( '*' );
        gotoxy( 1, XINI );
    for (i = 1; i < YFIM; i++) putch( '*' );
    for (i = 2; i < YFIM; i++)
    {
        putchxy( 1, i, '*' );
        putchxy( XINI, i, '*' );
    }
}
