/*
Esse programa recebe o numero de pessoas que estão em uma excursão e da como saida o numero minimo de quartos necessarios
*/

#include <stdio.h>
#define QUINZE 15 // Define QUINZE como constante com valor 15
#define SEIS 6 // Define SEIS como constante com valor 6
#define DOIS 2 // Define DOIS como constante com valor 2

int main()

{
    int pessoas; //Declaração da variável de entrada
    int quinze, seis, dois; //Declaração das variáveis intermediárias e de saída
    int quartos; //Declaração da variável de saída

    printf("Indique o numero de participantes da excursao: ");
    scanf("%d",&pessoas); //Ler a variável de entrada, o número de pessoas

    quinze = pessoas/QUINZE; // Cálculo para saber o número de quartos com 15 pessoas
    seis = (pessoas%QUINZE)/SEIS; //Cálculo para saber o número de quartos com 6 pessoas
    dois = ((pessoas%QUINZE)%SEIS)/DOIS; //Cálculo para saber o número de quartos com 2 pessoas
    dois += ((pessoas%QUINZE)%SEIS)%DOIS; //Cálculo para saber se restou 1 ou nenhuma pessoa, para assim alocar em um quarto de 2

    quartos = dois+seis+quinze; //Soma do número de quartos calculados anteriormente

    printf("\nSera necessario %d quartos: \n\n%d quarto(s) de quinze pessoas \n%d quarto(s) de seis pessoas \n%d quarto(s) de duas pessoas\n", quartos, quinze, seis, dois); /*
    Exibe a saída do programa, o menor número de quartos*/

    return(0); // Encerra o programa
}
