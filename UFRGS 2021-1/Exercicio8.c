/* Este programa recebe como entrada 4 vari�veis, sendo D e C iguais, e da como sa�da qual polinomio � possivel formar com as 4 medias:
um ret�ngulo, trap�zio ou quadrado. */

#include <stdio.h>

int main()
{
    int a, b, cd; //Declara��o das vari�veis de entrada

    printf("Indique o tamanho dos lados de um polinomio que possui 2 lados C e D\niguais para descobrir o seu tipo:\n");

    printf("\nTamanho do lado A: ");
    scanf("%d",&a); //Leitura do lado A

    printf("Tamanho do lado B: ");
    scanf("%d",&b); //Leitura do lado B

    printf("Tamanho dos lados C e D que sao iguais: ");
    scanf("%d",&cd); //Leitura dos lados C e D

    if (a == b) //Condi��o quando A == B
        if (a == cd) // Condi��o para quando todos lados s�o iguais
            printf("\nO polinomio e um QUADRADO(Q)\n");
        else //Condi��o quando A == B, por�m != de CD
            printf("\nO polinomio e um RETANGULO(R)\n");
    else //Condi��o quando A != de B
        printf("\nO polinomio e um TRAPEZIO(T)\n");
    return(0); //Acaba o programa

}

