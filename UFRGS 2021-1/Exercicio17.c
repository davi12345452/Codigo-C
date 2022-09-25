/*
O programa le uma frase que contem 100 caracteres, assim, o programa identifica as strings
identificando quantas palavras possuem de 1 a 10 caracteres.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO_MAX_FREQUENCIA 10 //Constante do valor do tamanho do arranjo frequencia
#define TAMANHO_MAX_CARACT 100 //Constante do valor do tamanho do arranjo cadeia_caracter
#define ZERO 0 // Constante 0
#define UM 1 // Constante 1

int main ()
{
    int frequencia [TAMANHO_MAX_FREQUENCIA] = {ZERO}; //Declaraçao do arranjo da frequencia de strings
    char cadeia_caracter [TAMANHO_MAX_CARACT]; //Declaracao do arranjo de caracteres que guarda a frase
    char *str; //Variável usada com a funçao STRTOK que separa a cadeia de caracteres em string
    int tamanho, i, tamanho_str, marcador; //Outras variáveis usadas no programa


    do //Comando repetição
    {
        printf("Digite uma frase com no maximo %d caracteres:\n\n", TAMANHO_MAX_CARACT);
        gets(cadeia_caracter); //Le a frase escrita pelo usuário
        tamanho = strlen(cadeia_caracter); //Define o tamanho da frase em espacos de caracter
        if (tamanho > TAMANHO_MAX_CARACT) //Condição caso a frase seja maior que o tamanho do arranjo
            printf("\nERRO, Voce digitou uma frase com mais de %d caracteres.\n", TAMANHO_MAX_CARACT);
    }
    while(tamanho > TAMANHO_MAX_CARACT); //Enquanto o tamanho não for menos que o tamanho do arranjo, o programa será executado

    printf("\n\nA frase digitada foi:\n\n%s\n\n", cadeia_caracter);

    str = strtok(cadeia_caracter, " "); //Separa a primeira palavra da cadeia de caracteres

    while(str != '\0')//Comando de repetição para ler cada string e identificar cada tamanho
    {
        tamanho_str = strlen(str); //Atribui o tamanho da string separada a tamanho_str
        str = strtok('\0', " "); //Separa a palavra seguinte
        marcador = tamanho_str - UM; //Retira um do tamanho, já que a primeira posição é 0 e não 1
        frequencia[marcador] += UM; // Adiciona mais um à string com o tamanho corresponde
    }

    for (i = ZERO; i < TAMANHO_MAX_FREQUENCIA; i++) //Comando de repetição para exibir o resultado do programa
        printf("Strings com %d caracteres: %d\n", (i+UM), frequencia[i]);
    return(ZERO); //Encerra a função main
}

