/*
Conjunto de exercícios envolvendo arranjos. Há inicialmente um arranjo formado aleatoriamente com rand,
depois disso, substituímos o último valor do arranjo por um valor escrito pelo usuário. Após isso, pegamos
as posições pares do arranjo e substiuímos pelo valor numérico da posição se fosse par. Então calculamos a
media dos termos do arranja e exibimos quantos termos estão acima dessa media.
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
    int arr[TAMANHO]; // Declaração do arranjo
    int random; // Declaração de variável intermediária
    int i; // Declaração de variável intermediaria
    int valor; // Declaração de variável de entrada
    int media, soma; //Declaração de variáveis intermediária
    int contador; //Declaração de variável intermediária e de saída


    printf("Declarando um arranjo gerado com numeros aleatorios\n\n");


    srand(time(CONSTANTE_ZERO)); //Gera uma nova cadeia de números aleatórios

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Comando de repetição para definir os termos do arranjo
    {
        random = (rand() % VALOR_MAXIMO); //Gera um número aleatório de 0 a 100
        arr[i] = random; //Define o número aleatorio como uma posição do arranjo
        printf("%-5d", random); //Imprime esse valor aleatório
    }



    printf("\n\nDigite um valor: "); //Mensagem antes de executar o scanf
    scanf("%d", &valor); // Le um número
    printf("\nLendo um numero, incorporando ele ao arranjo e empurrando\na esquerda os outros termos\n\n");

    for (i = CONSTANTE_UM; i < TAMANHO; i++) //Comando de repetição para deslocar os números uma casa à esquerda
        arr[i - CONSTANTE_UM] = arr [i];

    arr[CONSTANTE_NOVE] = valor; // Define como último número do arranjo o número lido

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Imprime os números do arranjo
        printf("%-5d", arr[i]);



    printf("\n\nSubstituindo as posicoes pares do arranjo por esse mesmo numero par\n\n");



    for(i = CONSTANTE_ZERO; i < TAMANHO; i++) //Altera os termos das posições pares pelo valor da posição
        if ((i % CONSTANTE_DOIS) == CONSTANTE_ZERO)
            arr[i] = i;

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Imprime os números do arranjo
        printf("%-5d", arr[i]);



    printf("\n\nContando quantos numeros sao maiores que a media do arranjo\n\n");



    for (i = CONSTANTE_ZERO; i < TAMANHO; i++) //Faz a soma dos termos do arranjo
        soma = soma + arr[i];

    media = soma / CONSTANTE_DEZ; //Calcula a media dos termos do arranjo

    contador = CONSTANTE_ZERO; //Define contador igual a 0

    for (i = CONSTANTE_ZERO; i < TAMANHO; i++)//Verifica quantos termos são maiores que a media
        if (arr[i] > media)
            contador = contador + CONSTANTE_UM; //Contador que acumula quantos termos são maiores que a media

    printf("Existem %d numeros que sao maiores que a media.\n\n", contador);

    return(0); //Encerra o programa
}
