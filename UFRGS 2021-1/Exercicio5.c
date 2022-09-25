/*
Este programa recebe o raio de um circulo como entrada, fornencendo como saída, sua área e seu perímetro */

#include <stdio.h>
#define PI 3.1416 //Constante PI definida como 3.1416

int main()
{
    float raio; //Define a variavel de entrada, o raio
    float area, peri; //Define as variaveis de saida, area e perimetro, respectivamente

    printf("Indique o raio do circulo: ");
    scanf("%f",&raio); //Ler o valor do raio

    area = PI * (raio*raio); // Expressão para o cálculo da área do círculo
    peri = 2 * PI * raio; // Expressão para o cálculo do perímetro do círculo

    printf("\nA area do circulo e: %.2f\n",area); //Exibe a saída "area" do programa
    printf("O perimetro do circulo e: %.2f\n", peri); //Exibe a saída "peri" do programa

    return(0); //Encerra o programa
    }
