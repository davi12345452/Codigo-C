/*
Este programa lê um intervalo temporal representado em horas, minutos e segundos, tranformando-o totalmente em segundos */

#include <stdio.h>
#define A 60 // Define A como constante que vale 60, para utilizar nas conversões

int main()
{
    int hora, min, seg; // Declaração das variáveis de entrada
    int seg2; // Declaração da variável de entrada e saída

    printf("Indique o intervalo temporal, escrevendo suas hora(s), minuto(s) e segundo(s):");

    printf("\nHora(s):");
    scanf("%d",&hora); // Ler as horas do intervalo

    printf("Minuto(s): ");
    scanf("%d",&min); // Ler os minutos do intervalo

    printf("Segundo(s): ");
    scanf("%d",&seg); // Ler os segundos do intervalo

    seg2 += (hora*A*A); // Adicionar o tempo em horas convertidos para segundos
    seg2 += (min*A); // Adicionar o tempo em minutos convetidos para segundos
    seg2 += seg; //Adicionar o tempo em segundos

    printf("\nO intervalo temporal de %d hora(s) %d minuto(s) e %d segundo(s) convertidos em segundos foi %d\n",hora, min, seg, seg2); //Exibir o resultado, saída, do programa

    return(0); //Encerra o programa
}
