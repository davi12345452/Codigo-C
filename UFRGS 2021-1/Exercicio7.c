/*
Esse programa recebe o numero de pessoas que est�o em uma excurs�o e da como saida o numero minimo de quartos necessarios
*/

#include <stdio.h>
#define QUINZE 15 // Define QUINZE como constante com valor 15
#define SEIS 6 // Define SEIS como constante com valor 6
#define DOIS 2 // Define DOIS como constante com valor 2

int main()

{
    int pessoas; //Declara��o da vari�vel de entrada
    int quinze, seis, dois; //Declara��o das vari�veis intermedi�rias e de sa�da
    int quartos; //Declara��o da vari�vel de sa�da

    printf("Indique o numero de participantes da excursao: ");
    scanf("%d",&pessoas); //Ler a vari�vel de entrada, o n�mero de pessoas

    quinze = pessoas/QUINZE; // C�lculo para saber o n�mero de quartos com 15 pessoas
    seis = (pessoas%QUINZE)/SEIS; //C�lculo para saber o n�mero de quartos com 6 pessoas
    dois = ((pessoas%QUINZE)%SEIS)/DOIS; //C�lculo para saber o n�mero de quartos com 2 pessoas
    dois += ((pessoas%QUINZE)%SEIS)%DOIS; //C�lculo para saber se restou 1 ou nenhuma pessoa, para assim alocar em um quarto de 2

    quartos = dois+seis+quinze; //Soma do n�mero de quartos calculados anteriormente

    printf("\nSera necessario %d quartos: \n\n%d quarto(s) de quinze pessoas \n%d quarto(s) de seis pessoas \n%d quarto(s) de duas pessoas\n", quartos, quinze, seis, dois); /*
    Exibe a sa�da do programa, o menor n�mero de quartos*/

    return(0); // Encerra o programa
}
