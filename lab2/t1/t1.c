// Davi Janisch Maia
// Lab2 - Trabalho 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

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

// Função que transforma um valor minúsculo e maiúsculo
// Verifica se é ou maiúculo e, caso não for, o transforma.
// Verifica de acordo com o ASCII do caracter -> StackOverflow
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Função que verifica se um char digitado é uma das duas opções disponíveis. Caso
// não for, entra em um loop até o usuário digitar corretamente. Pode ser digitado
// tanto minúsculo, quanto maiúculo.
void ler_char(char *mensagem, char *valor, char caract1, char caract2) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    scanf("%c", valor);

    // Converter para maiúsculo
    *valor = to_upper(*valor);

    while (*valor != to_upper(caract1) && *valor != to_upper(caract2)) {
        printf("Entrada inválida. Digite %c ou %c: ", to_upper(caract1), to_upper(caract2));
        getchar(); // Limpar buffer do teclado
        scanf("%c", valor);

        // Converter para maiúsculo
        *valor = to_upper(*valor);
    }
}


void ler_string(char *mensagem, char *str) {
    printf("%s", mensagem);
    getchar(); // Limpar buffer do teclado
    fgets(str, T_STRING, stdin);

    // Remover o caractere de nova linha no final da string
    /*
        Ao usar o fgets, caso haja espaço para mais caracteres e se clicar enter para enviar
        ele vai colocar o \n dentro da string. Precisei tirar para ajudar na formatação do re-
        latório.
    */
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

//Função que recebe os dados de entrada das pessoas
void recebeDadosEntrada(int tamanhoV, Pessoa vetor[tamanhoV]){
    printf("***************************************");
    printf("\n\tCADASTRO DE PESSOAS\n");
    printf("Obs.: Use ',' ao invés de '.' para nú-\nmeros com ponto flutuante(float)!\n");
    for(int i = 0; i < tamanhoV; i++){
        printf("---------------------------------------");
        printf("\n\tCadastro da pessoa %d:\n", i+1);
        printf("---------------------------------------");
        ler_int("\nDigite o código: ", &vetor[i].codigo);
        ler_string("Digite o nome: ", vetor[i].nome);
        ler_string("Digite o endereço: ", vetor[i].endereco);
        ler_float("Digite o peso(kg): ", &vetor[i].peso);
        ler_int("Digite a altura(cm): ", &vetor[i].altura);
        ler_char("Digite o sexo(F/M): ", &vetor[i].sexo, 'f', 'm');
        ler_float("Digite o salário(R$/mês): ", &vetor[i].salario);
    }
    printf("---------------------------------------\n");
}

/*
    Vou criar duas funções para cada relatório, uma que devolva os valores
    como na media de peso das mulheres, outra para gerar o relatório para o
    usuário.
*/
void mostraDados(int tamanhoV, Pessoa pessoas[tamanhoV]){
    printf("\n**************************************************");
    printf("\n*         DADOS DE PESSOAS CADASTRADAS           *\n");
    for (int i = 0; i < tamanhoV; i++) {
        printf("--------------------------------------------------\n");
        printf("|              Pessoa número %-2d                  |\n", i + 1);
        printf("--------------------------------------------------\n");
        printf("| Código:     %-34d |\n", pessoas[i].codigo);
        printf("| Nome:       %-34s |\n", pessoas[i].nome);
        printf("| Endereço:   %-34s |\n", pessoas[i].endereco);
        printf("| Peso(kg):   %-34.2f |\n", pessoas[i].peso);
        printf("| Altura(cm): %-34d |\n", pessoas[i].altura);
        printf("| Sexo:       %-34c |\n", pessoas[i].sexo);
        printf("| Salário:    R$%-32.2f |\n", pessoas[i].salario);
    }
    printf("--------------------------------------------------\n");
};
//void mediaPesoMulheres(){};
//void salarioHomens(){};
void mostrarIMC(int tamanhoV, Pessoa pessoas[tamanhoV]){
    float imc, peso, altura;
    printf("\n----------------------\n");
    printf("|   Relatório IMCs   |\n");
    printf("----------------------\n");
    for(int i = 0; i < tamanhoV; i++){
       altura = (float) pessoas[i].altura *0.01;
       peso = pessoas[i].peso;
       imc = peso/(altura * altura);
       printf("| IMC Pessoa %d: %-2.2f |\n", i, imc);
    }
    printf("----------------------\n");
};
//void pessoaMaisAlta(){};
//void codigoMaisBaixa(){};
//void numPesSalarioAcimaMedia(){};



int main(){
    //Variável para definir a quantidade de pessoas a serem computadas
    int tamanhoVetor = 1;
    Pessoa *vetorPessoas[tamanhoVetor];

    //Deixando a linguagem em português, para aceitar acentos e caracteres especiais
    setlocale(LC_ALL, "portuguese");

    recebeDadosEntrada(tamanhoVetor, &vetorPessoas);
    //mostraDados(tamanhoVetor, vetorPessoas);
    mostrarIMC(tamanhoVetor, vetorPessoas);

    return 0;
}
