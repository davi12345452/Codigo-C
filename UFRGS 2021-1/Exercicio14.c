/*
Este programa usa a formula pow(Pi, 2) = 8/pow(1, 2) + 8/pow(3, 2) + 8/pow(5, 2) + ...
para calcular um valor aproximado de Pi, havendo uma toler�ncia E, que, quando:
E > 8/pow(x, 2), a soma � parada, chegando a um valor aproximado de Pi ao quadrado, assim
calculamos sua raiz.
*/

#include <stdio.h>
#include <math.h>
#define E 0.001 //defini��o da constante toler�ncia
#define ZERO 0 //defini��o da constante ZERO
#define VALOR_INICIAL_SOMA_DENOMINADOR 1 //defini��o da constante do valor inicial da soma do denominador
#define OITO 8 // defini��o da constante OITO
#define DOIS 2 // defini��o da constante DOIS

int main()
{
    double numero = OITO ; //declara��o da vari�vel intermedi�ria numero, com valor inicial 8
    double soma = ZERO; //declara��o da vari�vel intermedi�ria soma, com valor inicial 0
    int soma_denominador_numero = VALOR_INICIAL_SOMA_DENOMINADOR; //declara��o da vari�vel intermedi�ria soma_denominador_numero, com valor inicial 1
    double valor_pi; //declara��o da vari�vel de sa�da

    while(numero >= E) //comando de repeti��o que s� para quando numero for menor que E
    {
        soma = soma + numero; //Soma � vari�vel soma o valor da vari�vel numero
        soma_denominador_numero = soma_denominador_numero + DOIS; // Somat�rio, que mantem o denominador um valor �mp�r com a soma de 2
        numero = OITO / pow(soma_denominador_numero, DOIS); //C�lculo de n�mero
    }

    valor_pi = sqrt(soma); //Tirando a raiz da soma, que vala aproximadamente Pi ao quadrado
    printf("\nO valor aproximado de Pi e %f\n", valor_pi); //Impress�o do valor aproximado de Pi
    return(0); //Encerra o programa
}
