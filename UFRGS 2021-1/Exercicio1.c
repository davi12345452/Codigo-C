/*
Este programa pega dois inteiros, os soma e exibe o resultado na tela
*/
#include <stdio.h>
int main(void)
{
int a, b; /*Declara��o da vari�vel com os par�metros */
int soma; /*Declara��o da vari�vel com o resultado*/
a = 2;
b = 3;
soma = a + b;
printf("Resultado da soma: %d", soma);
getchar();
printf("Terminou");
/*
O comando getchar() p�ra o programa ate que seja digitado algum caracter */
return(0);
}
