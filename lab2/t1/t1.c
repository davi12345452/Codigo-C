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
    printf("\tCadastro de pessoas.\n");
    for(int i = 0; i < tamanhoV; i++){
        printf("\n\tCadastro pessoa %d:", i);
        ler_int("\nDigite o c�digo: ", &vetor[i].codigo);
        ler_string("Digite o nome: ", vetor[i].nome);
        ler_string("Digite o endere�o: ", vetor[i].endereco);
        ler_float("Digite o peso(kg): ", &vetor[i].peso);
        ler_int("Digite a altura(cm): ", &vetor[i].altura);
        ler_char("Digite o sexo: ", &vetor[i].sexo, "F", "M");
        ler_float("Digite o sal�rio: ", &vetor[i].salario);
    }
}

int main(){
    //Vari�vel para definir a quantidade de pessoas a serem computadas
    int tamanhoVetor = 2;
    Pessoa *vetorPessoas[tamanhoVetor];

    //Deixando a linguagem em portugu�s, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    recebeDadosEntrada(tamanhoVetor, &vetorPessoas);

    return 0;
}
