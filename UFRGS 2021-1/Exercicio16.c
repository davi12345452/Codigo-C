/*
Conjunto de exerc�cios envolvendo arranjos. H� inicialmente um arranjo formado aleatoriamente com rand,
depois disso, substitu�mos o �ltimo valor do arranjo por um valor escrito pelo usu�rio. Ap�s isso, pegamos
as posi��es pares do arranjo e substiu�mos pelo valor num�rico da posi��o se fosse par. Ent�o calculamos a
media dos termos do arranja e exibimos quantos termos est�o acima dessa media.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10 //Constante com o tamanho do arranjo
#define VALOR_MAXIMO 100 //Valor maximo para usar no rand
#define CONSTANTE_UM 1   //Constante valor 1
#define CONSTANTE_ZERO 0 //Constante valor 0
#define CONSTANTE_NOVE 9 //Constante valor 9
#define CONSTANTE_DOIS 2 //Constante valor 2
#define CONSTANTE_DEZ 10 //Constante valor 10


int main ()
{
    int arr[TAMANHO]; // Declara��o do arranjo
    int random; // Declara��o de vari�vel intermedi�ria
    int i; // Declara��o de vari�vel intermediaria
    int valor; // Declara��o de vari�vel de entrada
    int media, soma; //Declara��o de vari�veis intermedi�ria
    int contador; //Declara��o de vari�vel intermedi�ria e de sa�da


    printf("Declarando um arranjo gerado com numeros aleatorios\n\n");


    srand(time(CONSTANTE_ZERO)); //Gera uma nova cadeia de n�meros aleat�rios

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Comando de repeti��o para definir os termos do arranjo
    {
        random = (rand() % VALOR_MAXIMO); //Gera um n�mero aleat�rio de 0 a 100
        arr[i] = random; //Define o n�mero aleatorio como uma posi��o do arranjo
        printf("%-5d", random); //Imprime esse valor aleat�rio
    }



    printf("\n\nDigite um valor: "); //Mensagem antes de executar o scanf
    scanf("%d", &valor); // Le um n�mero
    printf("\nLendo um numero, incorporando ele ao arranjo e empurrando\na esquerda os outros termos\n\n");

    for (i = CONSTANTE_UM; i < TAMANHO; i++) //Comando de repeti��o para deslocar os n�meros uma casa � esquerda
        arr[i - CONSTANTE_UM] = arr [i];

    arr[CONSTANTE_NOVE] = valor; // Define como �ltimo n�mero do arranjo o n�mero lido

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Imprime os n�meros do arranjo
        printf("%-5d", arr[i]);



    printf("\n\nSubstituindo as posicoes pares do arranjo por esse mesmo numero par\n\n");



    for(i = CONSTANTE_ZERO; i < TAMANHO; i++) //Altera os termos das posi��es pares pelo valor da posi��o
        if ((i % CONSTANTE_DOIS) == CONSTANTE_ZERO)
            arr[i] = i;

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Imprime os n�meros do arranjo
        printf("%-5d", arr[i]);



    printf("\n\nContando quantos numeros sao maiores que a media do arranjo\n\n");



    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Faz a soma dos termos do arranjo
        soma = soma + arr[i];

    media = soma / CONSTANTE_DEZ; //Calcula a media dos termos do arranjo

    contador = CONSTANTE_ZERO; //Define contador igual a 0

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++)//Verifica quantos termos s�o maiores que a media
        if (arr[i] > media)
            contador = contador + CONSTANTE_UM; //Contador que acumula quantos termos s�o maiores que a media

    printf("Existem %d numeros que sao maiores que a media.\n\n", contador);

    return(0); //Encerra o programa
}
