#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define T_STR_CIDADES 50

struct municipio
{
    char* nome;
    int populacao;
    int** dados; //matriz de dados
};
typedef struct municipio Municipio;

/*
    A matriz de inteiros com aloca��o din�mica possuir� n linhas (O usu�rio escolher�)
    contendo o dia, novos casos e novos �bitos. Preciso de uma fun��o principal para
    receber os dados e auxiliares para n�o deix�-la desorganizada. Al�m disso, preci-
    so de uma fun��o principal, com suas auxiliares, para dar a sa�da.
*/

// Fun��es para receber a string e os inteiros:
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

void ler_string(char *mensagem, char **str) {

    printf("%s", mensagem);
    scanf("%m[^\n]", &str);

}

int main(){
    //Linguagem em Portugu�s
    setlocale(LC_ALL, "portuguese");
    char *string;
    ler_string("teste", &string);
    printf("%s", &string);
    free(string);

}
