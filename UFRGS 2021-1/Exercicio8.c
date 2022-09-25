/* Este programa recebe como entrada 4 variáveis, sendo D e C iguais, e da como saída qual polinomio é possivel formar com as 4 medias:
um retângulo, trapézio ou quadrado. */

#include <stdio.h>

int main()
{
    int a, b, cd; //Declaração das variáveis de entrada

    printf("Indique o tamanho dos lados de um polinomio que possui 2 lados C e D\niguais para descobrir o seu tipo:\n");

    printf("\nTamanho do lado A: ");
    scanf("%d",&a); //Leitura do lado A

    printf("Tamanho do lado B: ");
    scanf("%d",&b); //Leitura do lado B

    printf("Tamanho dos lados C e D que sao iguais: ");
    scanf("%d",&cd); //Leitura dos lados C e D

    if (a == b) //Condição quando A == B
        if (a == cd) // Condição para quando todos lados são iguais
            printf("\nO polinomio e um QUADRADO(Q)\n");
        else //Condição quando A == B, porém != de CD
            printf("\nO polinomio e um RETANGULO(R)\n");
    else //Condição quando A != de B
        printf("\nO polinomio e um TRAPEZIO(T)\n");
    return(0); //Acaba o programa

}

