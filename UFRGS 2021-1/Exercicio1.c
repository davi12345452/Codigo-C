/*
Este programa pega dois inteiros, os soma e exibe o resultado na tela
*/
#include <stdio.h>
int main(void)
{
int a, b; /*Declaração da variável com os parâmetros */
int soma; /*Declaração da variável com o resultado*/
a = 2;
b = 3;
soma = a + b;
printf("Resultado da soma: %d", soma);
getchar();
printf("Terminou");
/*
O comando getchar() pára o programa ate que seja digitado algum caracter */
return(0);
}
