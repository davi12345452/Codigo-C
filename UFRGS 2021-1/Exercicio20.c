/*
Esse programa conforme alteramos o valor da constante através do próprio código,
fornece uma matriz de números e a media da soma dos número que estão abaixo da
antidiagonal. O programa, porém, só funciona quando a constante é um número
ímpar, caso contrário exibe uma mensagem de erro.
*/


#include <stdio.h>
#include <stdlib.h>

#define N 7 //Constante usada para definir o tamanho da matriz quadrada N x N
#define ZERO 0 //Constante zero para usar no programa
#define UM 1 //Constante um com valor 1 para usar no programa]


int main()
{
    int matriz[N][N] = {ZERO}; //Declaração da matriz usada no programa, incialmente igualada à zero
    int i, j, c_diagonal; //Declaração das variáveis intermediárias
    float media, total, contador; //Declaração da variável de saída

    media = ZERO; //Atribuindo valor inicial 0 à variável media
    total = ZERO; //Atribuindo valor inicial 0 à variável media
    contador = ZERO; //Atribuindo valor inicial 0 à variável media
    c_diagonal = N - UM; //Atribui valor N - 1 a variável usada na condição para calcular media

    if (N % 2 != ZERO) //Condição para que o programa só funcione com N ímpar
    {
        for (i = ZERO; i < N; i++) //Comando de repetição para formar a imagem do arranjo e calcular a media dos termos da antidiagonal
        {


            for(j = ZERO; j < N; j++) //Forma a imagem do arranjo
            {

                matriz[i][j] = i + j;
                printf("%-4d", matriz[i][j]);
            }


            for(j = ZERO; j < N; j++)//Calcula a soma e a quantidade de termos da antidiagonal
            {
                if(j > (c_diagonal - i)) //Condição de pertencer a antidiagonal
                {
                    contador += UM; //Divisor do cálculo da media
                    total += matriz[i][j]; //Dividendo do cálculo da media
                }
            }

            printf("\n"); //Para pular a linha quando cada uma estiver completa
        }

        media = total / contador; //cálculo para fazer a media da soma dos elementos da antidiagonal
        printf("\n\nA media da soma dos valores abaixo da antidiagonal e: %.2f\n", media); // Impressão da media

    }

    else //Condição caso N seja um número par
        printf("\nO valor de N e par, logo o programa nao pode ser executado\n");

    return(ZERO); //Termina o programa
}
