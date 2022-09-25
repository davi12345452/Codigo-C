/*
Este programa recebe 3 identificadores de produtos e seus respectivos valores, calculando o ICMS medio entre os 3, levando como base o ICMS de 17% do RS
*/
#include <stdio.h>
#define I 0.17 // Define 0.17 como constante para calcular ICMS de 17%

int main()
{
    char um, dois, tres; //declara��o das vari�veis de entrada
    float v1, v2, v3; //declara��o das vari�veis de entrada
    float ICMSm; //declara��o das vari�veis de sa�da

    printf("Indique o identificador(apenas uma letra) de 3 produtos e\nseus valores para descobrir o ICMS medio pago por cada um:\n");
    /*
    Explica��o de como utilizar e qual o objetivo do programa */

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

    v1 = v1*I; //c�lculo ICMS do primeiro produto cadastrado
    v2 = v2*I; //c�lculo ICMS do segundo produto cadastrado
    v3 = v3*I; //c�lculo ICMS do terceiro produto cadastrado

    ICMSm = (v1+v2+v3)/3; //c�lculo do ICMS m�dio entre os 3 produtos cadastrados

    printf("O ICMS medio, pago nos produtos com os identificadores %c, %c e %c, foi R$%.2f\n",um,dois,tres,ICMSm); /*
    Final do programa, indicando o ICMS m�dio e os identificadores dos produtos*/

    return(0); //Encerra o programa
}


