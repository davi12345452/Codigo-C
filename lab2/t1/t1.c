// Davi Janisch Maia
// Lab2 - Trabalho 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

//Constante para tamanho de string dos char[] com tamanho 80, sem contar o \0
#define T_STRING 81

struct pessoa {
int codigo;
char nome[T_STRING];
char endereco[T_STRING];
float peso;
int altura;
char sexo;
float salario;
};

typedef struct pessoa Pessoa;

// Fun��o que l� um inteiro e salva em um local da mem�ria
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

// Fun��o que l� um n�mero de ponto flutuante e e salva em
// um local da mem�ria
void ler_float(char *mensagem, float *valor) {
    printf("%s", mensagem);
    scanf("%f", valor);
}


// Essa fun��o serve para ler um caractere e, verificar se ele � aos
// 2 poss�veis. Al�m disso, a fun��o deixa esses caracteres salvos
// mai�sculos.
void ler_char(char *mensagem, char *valor, char resp1, char resp2) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    scanf("%c", valor);
    *valor = toupper(*valor); // Converter para mai�sculo

    while (*valor != resp1 && *valor != resp2) {
        printf("Entrada inv�lida. Digite %c ou %c: ", resp1, resp2);
        getchar(); // Limpar buffer do teclado
        scanf("%c", valor);
        *valor = toupper(*valor);
    }
}

// Essa fun��o l� uma string e salva em um local de mem�ria char[]
void ler_string(char *mensagem, char *str) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    fgets(str, T_STRING, stdin);
}

//Fun��o que recebe os dados de entrada das pessoas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){

}

int main(){
    //Vari�vel para definir a quantidade de pessoas a serem computadas
    int tamanhoVetor = 0;
    Pessoa *vetorPessoas[tamanhoVetor];

    return 0;
}
