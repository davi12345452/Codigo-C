/*
Este programa recebe 3 identificadores de produtos e seus respectivos valores, calculando o ICMS medio entre os 3, levando como base o ICMS de 17% do RS
*/
#include <stdio.h>
#define I 0.17 // Define 0.17 como constante para calcular ICMS de 17%

int main()
{
    char um, dois, tres; //declaração das variáveis de entrada
    float v1, v2, v3; //declaração das variáveis de entrada
    float ICMSm; //declaração das variáveis de saída

    printf("Indique o identificador(apenas uma letra) de 3 produtos e\nseus valores para descobrir o ICMS medio pago por cada um:\n");
    /*
    Explicação de como utilizar e qual o objetivo do programa */

    printf("\nIdentificador do primeiro produto: ");
    scanf(" %c",&um); //Ler o identificador do primeiro produto
    printf("Seu valor: ");
    scanf("%f",&v1); //Ler o valor do primeiro produto

    printf("\nIdentificador do segundo produto: ");
    scanf(" %c",&dois); //Ler o identificador do segundo produto
    printf("Seu valor: ");
    scanf("%f",&v2); //Ler o valor do segundo produto

    printf("\nIdentificador do terceiro produto: ");
    scanf(" %c",&tres); //Ler o identificador do terceiro produto
    printf("Seu valor: ");
    scanf("%f",&v3); //Ler o valor do terceiro produto

    v1 = v1*I; //cálculo ICMS do primeiro produto cadastrado
    v2 = v2*I; //cálculo ICMS do segundo produto cadastrado
    v3 = v3*I; //cálculo ICMS do terceiro produto cadastrado

    ICMSm = (v1+v2+v3)/3; //cálculo do ICMS médio entre os 3 produtos cadastrados

    printf("O ICMS medio, pago nos produtos com os identificadores %c, %c e %c, foi R$%.2f\n",um,dois,tres,ICMSm); /*
    Final do programa, indicando o ICMS médio e os identificadores dos produtos*/

    return(0); //Encerra o programa
}


