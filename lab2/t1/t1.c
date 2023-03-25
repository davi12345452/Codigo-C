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

// Função que lê um inteiro e salva em um local da memória
void ler_int(char *mensagem, int *valor) {
    printf("%s", mensagem);
    scanf("%d", valor);
}

// Função que lê um número de ponto flutuante e e salva em
// um local da memória
void ler_float(char *mensagem, float *valor) {
    printf("%s", mensagem);
    scanf("%f", valor);
}

// Essa função serve para ler um caractere e, verificar se ele é aos
// 2 possíveis. Além disso, a função deixa esses caracteres salvos
// maiúsculos.
void ler_char(char *mensagem, char *valor, char resp1, char resp2) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    scanf("%c", valor);
    *valor = toupper(*valor); // Converter para maiúsculo

    while (*valor != resp1 && *valor != resp2) {
        printf("Entrada inválida. Digite %c ou %c: ", resp1, resp2);
        getchar(); // Limpar buffer do teclado
        scanf("%c", valor);
        *valor = toupper(*valor);
    }
}

// Essa função lê uma string e salva em um local de memória char[]
void ler_string(char *mensagem, char *str) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    fgets(str, T_STRING, stdin);
}

//Função que recebe os dados de entrada das pessoas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){
    printf("\tCadastro de pessoas.\n");
    for(int i = 0; i < tamanhoV; i++){
        printf("\n\tCadastro pessoa %d:", i);
        ler_int("\nDigite o código: ", &vetor[i].codigo);
        ler_string("Digite o nome: ", vetor[i].nome);
        ler_string("Digite o endereço: ", vetor[i].endereco);
        ler_float("Digite o peso(kg): ", &vetor[i].peso);
        ler_int("Digite a altura(cm): ", &vetor[i].altura);
        ler_char("Digite o sexo: ", &vetor[i].sexo, "F", "M");
        ler_float("Digite o salário: ", &vetor[i].salario);
    }
}

int main(){
    //Variável para definir a quantidade de pessoas a serem computadas
    int tamanhoVetor = 2;
    Pessoa *vetorPessoas[tamanhoVetor];

    //Deixando a linguagem em português, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    recebeDadosEntrada(tamanhoVetor, &vetorPessoas);

    return 0;
}
