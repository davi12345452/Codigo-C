// Davi Janisch Maia
// Lab2 - Trabalho 1

#include <stdio.h>


struct pessoa {
int codigo;
char nome[81];
char endereco[81];
float peso;
int altura;
char sexo;
float salario;
};

typedef struct pessoa Pessoa;

//Função que recebe os dados de entrada das pessoas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){
    for(int i = 0; i < tamanhoV; i++){
        printf("----------------------");
        printf("Cadastro da pessoa %d", i);
        printf("----------------------");
        scanf("", &);
        scanf("", &);
        scanf("", &);
        scanf("", &);
        scanf("", &);
        scanf("", &);
        scanf("", &);
        printf("----------------------");
    }
}

int main(){
    int tamanhoVetor = 0;
    Pessoa vetorPessoas[tamanhoVetor];

    return 0;
}
