/*
Este programa usa a formula pow(Pi, 2) = 8/pow(1, 2) + 8/pow(3, 2) + 8/pow(5, 2) + ...
para calcular um valor aproximado de Pi, havendo uma tolerância E, que, quando:
E > 8/pow(x, 2), a soma é parada, chegando a um valor aproximado de Pi ao quadrado, assim
calculamos sua raiz.
*/

#include <stdio.h>
#include <math.h>
#define E 0.001 //definição da constante tolerância
#define ZERO 0 //definição da constante ZERO
#define VALOR_INICIAL_SOMA_DENOMINADOR 1 //definição da constante do valor inicial da soma do denominador
#define OITO 8 // definição da constante OITO
#define DOIS 2 // definição da constante DOIS

int main()
{
    double numero = OITO ; //declaração da variável intermediária numero, com valor inicial 8
    double soma = ZERO; //declaração da variável intermediária soma, com valor inicial 0
    int soma_denominador_numero = VALOR_INICIAL_SOMA_DENOMINADOR; //declaração da variável intermediária soma_denominador_numero, com valor inicial 1
    double valor_pi; //declaração da variável de saída

    while(numero >= E) //comando de repetição que só para quando numero for menor que E
    {
        soma = soma + numero; //Soma à variável soma o valor da variável numero
        soma_denominador_numero = soma_denominador_numero + DOIS; // Somatório, que mantem o denominador um valor ímpár com a soma de 2
        numero = OITO / pow(soma_denominador_numero, DOIS); //Cálculo de número
    }

    valor_pi = sqrt(soma); //Tirando a raiz da soma, que vala aproximadamente Pi ao quadrado
    printf("\nO valor aproximado de Pi e %f\n", valor_pi); //Impressão do valor aproximado de Pi
    return(0); //Encerra o programa
}
