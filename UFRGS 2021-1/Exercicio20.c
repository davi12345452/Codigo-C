/*
Esse programa conforme alteramos o valor da constante atrav�s do pr�prio c�digo,
fornece uma matriz de n�meros e a media da soma dos n�mero que est�o abaixo da
antidiagonal. O programa, por�m, s� funciona quando a constante � um n�mero
�mpar, caso contr�rio exibe uma mensagem de erro.
*/


#include <stdio.h>
#include <stdlib.h>

#define N 7 //Constante usada para definir o tamanho da matriz quadrada N x N
#define ZERO 0 //Constante zero para usar no programa
#define UM 1 //Constante um com valor 1 para usar no programa]


int main()
{
    int matriz[N][N] = {ZERO}; //Declara��o da matriz usada no programa, incialmente igualada � zero
    int i, j, c_diagonal; //Declara��o das vari�veis intermedi�rias
    float media, total, contador; //Declara��o da vari�vel de sa�da

    media = ZERO; //Atribuindo valor inicial 0 � vari�vel media
    total = ZERO; //Atribuindo valor inicial 0 � vari�vel media
    contador = ZERO; //Atribuindo valor inicial 0 � vari�vel media
    c_diagonal = N - UM; //Atribui valor N - 1 a vari�vel usada na condi��o para calcular media

    if (N % 2 != ZERO) //Condi��o para que o programa s� funcione com N �mpar
    {
        for (i = ZERO; i < N; i++) //Comando de repeti��o para formar a imagem do arranjo e calcular a media dos termos da antidiagonal
        {


            for(j = ZERO; j < N; j++) //Forma a imagem do arranjo
            {

                matriz[i][j] = i + j;
                printf("%-4d", matriz[i][j]);
            }


            for(j = ZERO; j < N; j++)//Calcula a soma e a quantidade de termos da antidiagonal
            {
                if(j > (c_diagonal - i)) //Condi��o de pertencer a antidiagonal
                {
                    contador += UM; //Divisor do c�lculo da media
                    total += matriz[i][j]; //Dividendo do c�lculo da media
                }
            }

            printf("\n"); //Para pular a linha quando cada uma estiver completa
        }

        media = total / contador; //c�lculo para fazer a media da soma dos elementos da antidiagonal
        printf("\n\nA media da soma dos valores abaixo da antidiagonal e: %.2f\n", media); // Impress�o da media

    }

    else //Condi��o caso N seja um n�mero par
        printf("\nO valor de N e par, logo o programa nao pode ser executado\n");

    return(ZERO); //Termina o programa
}
