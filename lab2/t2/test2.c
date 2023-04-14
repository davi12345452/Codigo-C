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
    A matriz de inteiros com alocação dinâmica possuirá n linhas (O usuário escolherá)
    contendo o dia, novos casos e novos óbitos. Preciso de uma função principal para
    receber os dados e auxiliares para não deixá-la desorganizada. Além disso, preci-
    so de uma função principal, com suas auxiliares, para dar a saída.
*/

// Funções para receber a string e os inteiros:
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

void ler_string(char *mensagem, char **str) {

    printf("%s", mensagem);
    scanf("%m[^\n]", &str);

}

int main(){
    //Linguagem em Português
    setlocale(LC_ALL, "portuguese");
    char *string;
    ler_string("teste", &string);
    printf("%s", &string);
    free(string);

}
