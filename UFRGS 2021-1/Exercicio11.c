/*
O exercício pede para substituir a estrutura While por For, e a estrutura For por While.
*/

#include <stdio.h>
#include <stdlib.h>
#define VALOR 3

int main()

{

    float a;
    int i=0,k;
    a = 9;
    for ( i; i < VALOR; i++) //Para i, enquanto i é menor que valor, executar e somar 1 ao valor de i
    {
        k = i; //Atribuindo valor a variável k
        while(k <= (i+1)) //Enquanto k for menor ou igual a i+1, executar
        {
            if (i % 2 == 0)
            {
                if (k % 2 == 0)
                    a = a + k * 2;
                a-- ;
            }
            else
            {
                a = a * 2;
            }
            printf("%4d,%4d,%8.2f \n", i, k, a);
            k++; //Soma 1 ao valor de k
        }
    }
    return(0);
}
