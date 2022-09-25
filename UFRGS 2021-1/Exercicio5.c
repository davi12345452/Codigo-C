/*
Este programa recebe o raio de um circulo como entrada, fornencendo como sa�da, sua �rea e seu per�metro */

#include <stdio.h>
#define PI 3.1416 //Constante PI definida como 3.1416

int main()
{
    float raio; //Define a variavel de entrada, o raio
    float area, peri; //Define as variaveis de saida, area e perimetro, respectivamente

    printf("Indique o raio do circulo: ");
    scanf("%f",&raio); //Ler o valor do raio

    area = PI * (raio*raio); // Express�o para o c�lculo da �rea do c�rculo
    peri = 2 * PI * raio; // Express�o para o c�lculo do per�metro do c�rculo

    printf("\nA area do circulo e: %.2f\n",area); //Exibe a sa�da "area" do programa
    printf("O perimetro do circulo e: %.2f\n", peri); //Exibe a sa�da "peri" do programa

    return(0); //Encerra o programa
    }
